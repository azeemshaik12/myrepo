#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define size 1000
void reading(int fd){
 fd=open("/dev/rw_rm",O_RDWR);
char buffer[size];
printf("enter the no.of bytes to read\n");
int bsize;
scanf("%d",&bsize);
int z=read(fd,buffer,bsize);
printf("received message is\n:");
#if 1
for(int i=0;i<bsize;i++)
{
printf("%c",buffer[i]);
}
#endif

//printf("%s",buffer);
printf("\n");
close(fd);
}

void writing(int fd){
 fd=open("/dev/rw_rm",O_RDWR);
char buffer[size];
printf("Enter the data to be written:\n");
int bytes=read(STDIN_FILENO,buffer,size);
int y=write(fd,buffer,bytes-1);
close(fd);
}
#if 0
void exitfun(int fd){
        fd=open("/dev/rw_rm",O_RDWR);
        write(fd,"exit",5);
        close(fd);
}
#endif

int main(){
//int x=open("/dev/rw_rm",O_RDWR);
int x=10;
if(x<0){
        perror("open");
        return errno;
}
while(1){
int option;
printf("what would you like to do?\n1.Read\n2.write\n3.Exit\nEnter the option:\n");
scanf("%d",&option);
if(option==1){
reading(x);
}
else if(option==2){
writing(x);
}
else if(option==3){
        return 0;
}
sleep(1);
}
return 0;

}