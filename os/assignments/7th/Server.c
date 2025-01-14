

//DATE:31-12-16

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>

int  a[3];

void kil(int n)
{
 printf("\n the pipe is broken\n");
 kill(getpid(),SIGKILL);
}	
int* count(char*str)
{
 //static int a[3];
 while(*str)
 {
  if(((*str)>='A'&&(*str)<='Z')||((*str)>='a'&&(*str)<='z'))
   ++(a[0]); 
  else if((*str)>='0'&&(*str)<='9')
    ++(a[1]);
  else
    ++(a[2]);
  str++;
 }
 return a;
}

 int main()
{
 int fd1,fd2,i=0,*arr;
 char ch,*buf=0;
 struct sigaction t;
 fd1=open("fifo1",O_RDONLY);
 fd2=open("fifo2",O_WRONLY);
 t.sa_handler=kil;
 sigaction(SIGPIPE,&t,NULL);
 read(fd1,&i,4);
 printf("value of i=%d\n",i);
 buf=malloc(i);
 read(fd1,buf,i);
 printf("data recieved<%s>\n",buf);
 arr=count(buf);
 printf("alpha =%d,numeric=%d,special=%d\n",arr[0],arr[1],arr[2]);
 i=0; 
 while(i<3)
  write(fd2,arr+(i++),4);
}

