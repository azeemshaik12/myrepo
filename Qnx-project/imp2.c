#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#include <sys/resmgr.h>

/* Change to something else if sharing a target */
#define EXAMPLE_NAME "/dev/rw_rm"
#define MAX_SIZE 24
int exit_status=0;
char buffer[MAX_SIZE]; // made up data
void options(int argc, char *argv[]);

int io_open(resmgr_context_t *ctp, io_open_t  *msg, RESMGR_HANDLE_T *handle, void *extra);
int io_read(resmgr_context_t *ctp, io_read_t  *msg, RESMGR_OCB_T *ocb);
int io_write(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb);

resmgr_connect_funcs_t connect_funcs;
resmgr_io_funcs_t      io_funcs;

dispatch_t              *dpp;
resmgr_attr_t           rattr;
dispatch_context_t      *ctp;
iofunc_attr_t           ioattr;

int optv; // -v for verbose operation

int main(int argc, char *argv[]) {
        int ret;

    printf ("%s: Starting...\n", argv[0]);

    options(argc, argv);

       dpp = dispatch_create_channel(-1, DISPATCH_FLAG_NOLOCK);
    if (dpp == NULL) {
        int errno_bak = errno;
        fprintf(stderr, "Couldn't dispatch_create: %s\n", strerror(errno));
        return errno_bak;
    }



     iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs,
                      _RESMGR_IO_NFUNCS, &io_funcs);


    connect_funcs.open = io_open;
    io_funcs.read = io_read;
    io_funcs.write = io_write;


    iofunc_attr_init(&ioattr, S_IFCHR | 0666, NULL, NULL);


    ret = resmgr_attach(dpp, &rattr, EXAMPLE_NAME, _FTYPE_ANY, 0,
&connect_funcs, &io_funcs, &ioattr);
    if (ret == -1) {
        int errno_bak = errno;
        fprintf(stderr, "couldn't attach pathname: %s\n", strerror(errno));
        return errno_bak;
    }


    ctp = dispatch_context_alloc(dpp);
    if (ctp == NULL) {
        int errno_bak = errno;
        perror("dispatch_context_alloc");
        return errno_bak;
    }

    /* Our main operation loop */
    while (1) {
        /* Block waiting for client requests */
        if (dispatch_block(ctp) == NULL) {
                int errno_bak = errno;
            perror("dispatch_block");
            return errno_bak;
        }

        /* For debug purposes it can be useful to look at every message & pulse received */
        if (optv > 1) {
                if (ctp->message_context.rcvid == 0) {
                    printf("pulse code: %d\n", ctp->message_context.msg->pulse.code);
                }
                else {
                    printf("message type: %d\n", ctp->message_context.msg->type);
                }
        }

        /* Handle client requests, calling out into our handlers where appropriate */
        dispatch_handler(ctp);
         if(exit_status==1){
                 printf("%d\n",exit_status);
                return 0;
        }
    }
}



int io_open(resmgr_context_t *ctp, io_open_t *msg, RESMGR_HANDLE_T *handle, void *extra) {
    if (optv) {
        printf ("in io_open\n");
    }

    return iofunc_open_default (ctp, msg, handle, extra);
}

int io_read(resmgr_context_t *ctp, io_read_t *msg, RESMGR_OCB_T *ocb) {
        int status;
        static size_t nb, max_buf_size;
        if(strlen(buffer)==0){
         printf("buffer is empty\n");
         return 0;
        }
        printf("ocb->attr->nbytes: %d, ocb->offset: %d, msg->i.nbytes%d\n", ocb->attr->nbytes, ocb->offset, msg->i.nbytes);

        if (optv) {
                printf ("in io_read\n");
                if (optv > 1)
                        printf("ocb->offset: %d, msg->i.nbytes%d\n", ocb->offset, msg->i.nbytes);
        }

        if ((status = iofunc_read_verify(ctp, msg, ocb, NULL)) != EOK)
                return status;

        if ((msg->i.xtype & _IO_XTYPE_MASK) != _IO_XTYPE_NONE) {
                return ENOSYS;   // causes MsgError( ctp->rcvid, ENOSYS );
        }
        if (ocb->offset == 0) {
                nb = max_buf_size =msg->i.nbytes ;
        }

        if (ocb->offset < max_buf_size) {
                nb = min(nb - ocb->offset, msg->i.nbytes);
                printf("some debug\n");

                MsgReply(ctp->rcvid,nb,buffer + ocb->offset,nb);
                ocb->offset += nb;
        }
        else
                MsgReply(ctp->rcvid, EOK, NULL, 0);

        if (nb > 0) {
                ocb->attr->flags |= IOFUNC_ATTR_ATIME;
        }


         MsgReply(ctp->rcvid,nb,buffer + ocb->offset,nb);
         if(msg->i.nbytes>=MAX_SIZE)
                 buffer[0]='\0';
         else{
            memmove(buffer,buffer+msg->i.nbytes,MAX_SIZE-msg->i.nbytes);
            for(int i=MAX_SIZE-msg->i.nbytes;i<24;i++)
            buffer[i]='\0';

         }
        return _RESMGR_NOREPLY;
}

int io_write(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb) {
    int status;
    ssize_t nb;
    char dummy[MAX_SIZE];
    int size=0,msize;
    if(strlen(buffer)==0){
      size=0;
    }
    else{
    size=strlen(buffer);
    }

    if (optv) {
        printf("in io_write\n");
    }

    if ((status = iofunc_write_verify(ctp, msg, ocb, NULL)) != EOK) {
        return status;
    }

    if ((msg->i.xtype & _IO_XTYPE_MASK) != _IO_XTYPE_NONE) {
        return ENOSYS;
    }

    if( msg->i.nbytes == 0 ) {
        MsgReply(ctp->rcvid, 0, NULL, 0 );

        return _RESMGR_NOREPLY;
    }
     if(((size<MAX_SIZE)&&(size+msg->i.nbytes)>MAX_SIZE)){
      msg->i.nbytes=MAX_SIZE-size;
      printf("%d %d\n",msg->i.nbytes,size);
     }
     else{
             msg->i.nbytes=msg->i.nbytes;
         }
     nb = resmgr_msgget(ctp,dummy, msg->i.nbytes, sizeof(*msg));
    if(nb == -1) {
        return errno;
    }
    if (msg->i.nbytes > 0) {
        ocb->attr->flags |= IOFUNC_ATTR_MTIME | IOFUNC_ATTR_CTIME;
    }
    if((size+msg->i.nbytes)<=MAX_SIZE){
    memcpy(&buffer[size],dummy,msg->i.nbytes);
    }
    else{
            memcpy(buffer,dummy,msg->i.nbytes);
            buffer[msg->i.nbytes]='\0';
      }

   MsgReply(ctp->rcvid, msg->i.nbytes,buffer, strlen(buffer));
    printf("%s\n",buffer);


    return _RESMGR_NOREPLY;
}


void options(int argc, char *argv[]) {
    int opt;
    optv = 0;

    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
                        case 'v':
                                optv++;
                                break;
        }
    }
}