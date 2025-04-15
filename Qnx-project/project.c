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
//int exit_status=0;
char *buffer=NULL; // made up data
void options(int argc, char *argv[]);

/*
* These prototypes are needed since we are using their names in main ()
*/

int io_open(resmgr_context_t *ctp, io_open_t  *msg, RESMGR_HANDLE_T *handle, void *extra);
int io_read(resmgr_context_t *ctp, io_read_t  *msg, RESMGR_OCB_T *ocb);
int io_write(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb);
/*
* Our connect and I/O functions
*/
resmgr_connect_funcs_t connect_funcs;
resmgr_io_funcs_t      io_funcs;

/*
* Our dispatch, resource manager and iofunc variables
*/
dispatch_t              *dpp;
resmgr_attr_t           rattr;
dispatch_context_t      *ctp;
iofunc_attr_t           ioattr;

int optv; // -v for verbose operation

int main(int argc, char *argv[]) {
        int ret;

    printf ("%s: Starting...\n", argv[0]);

    options(argc, argv);

    /*
     * Allocate and initialize a dispatch structure for use by our
     * main loop
     */
    dpp = dispatch_create_channel(-1, DISPATCH_FLAG_NOLOCK);
    if (dpp == NULL) {
        int errno_bak = errno;
        fprintf(stderr, "Couldn't dispatch_create: %s\n", strerror(errno));
        return errno_bak;
    }

    /*
     * Set up the resource manager attributes structure, we'll
     * use this as a way of passing information to resmgr_attach().
     * For now, we just use defaults.
     */
    memset(&rattr, 0, sizeof(rattr)); /* Using the defaults for rattr */

    /*
     * Initialize the connect functions and I/O functions tables to
     * their defaults by calling iofunc_func_init().
     *
     * connect_funcs, and io_funcs variables are already declared.
     */
     iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs,
                      _RESMGR_IO_NFUNCS, &io_funcs);

    /*
     * Over-ride the connect_funcs handler for open with our io_open,
     * and over-ride the io_funcs handlers for read and write with our
     * io_read and io_write handlers
     */
    connect_funcs.open = io_open;
    io_funcs.read = io_read;
    io_funcs.write = io_write;

    /*
     * Initialize our device description structure
     */
    iofunc_attr_init(&ioattr, S_IFCHR | 0666, NULL, NULL);

    /*
     *  Call resmgr_attach to register our prefix with the
     *  process manager, and register our connect and I/O
     *  functions with the resmgr library.
     */
    ret = resmgr_attach(dpp, &rattr, EXAMPLE_NAME, _FTYPE_ANY, 0,
&connect_funcs, &io_funcs, &ioattr);
    if (ret == -1) {
        int errno_bak = errno;
        fprintf(stderr, "couldn't attach pathname: %s\n", strerror(errno));
        return errno_bak;
    }

    /*
     * Allocate the dispatch context for this resource manager,
     * this is the receive-loop data.
     */
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
        // if(exit_status==1){
        //       printf("%d\n",exit_status);
        //        return 0;
       // }
    }
}

/*
*  io_open
*
*  We are called here when the client does an open.
*  Do the default open handling and, if verbose, print.
*/

int io_open(resmgr_context_t *ctp, io_open_t *msg, RESMGR_HANDLE_T *handle, void *extra) {
    if (optv) {
        printf ("in io_open\n");
    }

    return iofunc_open_default (ctp, msg, handle, extra);
}

int io_read(resmgr_context_t *ctp, io_read_t *msg, RESMGR_OCB_T *ocb) {
        int status;
        static size_t nb, max_buf_size;
        if(buffer==NULL){
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
        if(strlen(buffer)!=0&&strlen(buffer)>=msg->i.nbytes){
        int size=strlen(buffer)-nb;
        memmove(buffer,buffer+nb,size);
        for(int i=strlen(buffer);i>=size;i--) buffer[i]='\0';
        buffer=realloc(buffer,size);
         printf("resized buffer is %s %d:\n",buffer,strlen(buffer));
         }
        else{
                printf("else part\n");
//              MsgReply(ctp->rcvid,strlen(buffer),buffer + ocb->offset,strlen(buffer));
                for(int i=0;i<strlen(buffer);i++)buffer[i]='\0';
        }
        return _RESMGR_NOREPLY;
}

int io_write(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb) {
    int status;
    char dummy[10000];
    ssize_t nb;
    int size;

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
   if(buffer == NULL) {
            buffer=calloc(1,1);
            size=0;
    }
    else{
        size=strlen(buffer);
        printf("buffer szie write is %d\n",size);
     }
     nb = resmgr_msgget(ctp,dummy, msg->i.nbytes, sizeof(*msg));
    char *ptr=realloc(buffer,nb);
     buffer=ptr;
     memcpy(&buffer[size],dummy,nb);
    if(nb == -1) {
        return errno;
    }
        printf("%s\n",buffer);

        MsgReply(ctp->rcvid, msg->i.nbytes,buffer, strlen(buffer));

    if (msg->i.nbytes > 0) {
        ocb->attr->flags |= IOFUNC_ATTR_MTIME | IOFUNC_ATTR_CTIME;
    }
   // printf("exit status %s\n",&buffer[strlen(buffer)-5]);
   // if(!strcmp(&buffer[strlen(buffer)-4],"exit")){
//                 exit_status=1;
//                 return _RESMGR_NOREPLY;
  //  }

    return _RESMGR_NOREPLY;
}

/*
*  options
*
*  This routine handles the command line options.
)*  For our simple /dev/example, we support:
*      -v verbose operation
*/
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