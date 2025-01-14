
//DATE:31-12-16

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>

void kil(int n)
{
  printf("\n the pipe is broken\n");
  kill(getpid(),SIGKILL);
}       

 int main()
{
 int fd1,fd2,i=0,a[3];
 char ch,*buf=0;
 struct sigaction t;
 
 //fd1=create("fifo1",O_WRONLY);
 fd1=open("fifo1",O_WRONLY);
 fd2=open("fifo2",O_RDONLY);
 t.sa_handler=kil;
 sigaction(SIGPIPE,&t,NULL);
 printf("please enter the data to be printed:");
 while((ch=getchar())!=10)
 {
  buf=realloc(buf,i+1);
  buf[i++]=ch;
 }
 printf("\nyou entered<%s>\n",buf);
 write(fd1,&i,4);
 write(fd1,buf,i);
 i=0;
 while(i<3)
 read(fd2,a+(i++),4);
 printf("alpha=%d|numeric=%d|special=%d|\n",a[0],a[1],a[2]);
}

