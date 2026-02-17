
//DATE: 3-1-17
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
 int fd1,fd2,i=0;
 char *buf,ch,gbuf[400]="\0";
 //if( mknod("fifo_1",0660|S_IFIFO,0)==-1)
// if(mknod("fifo_2",0660|S_IFIFO,0)==-1)
 fd1 = open("fifo_1",O_RDONLY);
 fd2 = open("fifo_2",O_WRONLY);
 printf("please enter the command to be executed: ");
while((ch=getchar())!='\n')
{
 buf = realloc(buf,i+i);
 buf[i++]=ch;
}
 write(fd2,&i,sizeof(int));
 write(fd2,buf,i);
 //close(0);
// fcntl(fd2,F_DUPFD,0);
 read(fd1,&gbuf,400);
 printf("the output is:\n%s",gbuf);
 //puts(gbuf);
// close(fd1); 
// close(fd2); 
}
