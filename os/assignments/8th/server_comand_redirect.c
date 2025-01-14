
//DATE:3-1-17
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
 int fd1,fd2,i=0;
 char *buf,ch;
 //if( mknod("fifo_1",0660|S_IFIFO,0)==-1)
// if(mknod("fifo_2",0660|S_IFIFO,0)==-1)
 fd1 = open("fifo_1",O_WRONLY);
 fd2 = open("fifo_2",O_RDONLY);
 read(fd2,&i,sizeof(int));
 //printf("the value of i=%d\n",i);
 buf=malloc(i);
 read(fd2,buf,i);
 close(1);
 //close(fd2);
 fcntl(fd1,F_DUPFD,1);
 system(buf);
 //close(fd1); 
 //close(fd2); 
}
