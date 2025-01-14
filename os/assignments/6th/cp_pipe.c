
//DATE:30-12-16
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
//#include<system.h>
 int main(int argc,char**argv)
{
 int p[2];
 pipe(p);
 if(argc!=3){printf("incorrect no of arguments\n");return 0;}
 
 if(fork())
 {
  int fds,size;
  char *buf;
  printf("inside parent:%d and its parent is:%d\n",getpid(),getppid());
  fds = open(argv[1],O_RDONLY);
  size=lseek(fds,0,2);
  lseek(fds,0,SEEK_SET);
  buf=malloc(size);
  read(fds,buf,size);
  printf("in parent buf:\n%s",buf);
  close(1);
  dup(p[1]);
  write(p[1],&size,4);
  write(p[1],buf,size);
 }
 else 
 {
  int fdd,size;
  char *buff;
  printf("inside child:%d and its parent is:%d\n",getpid(),getppid());
  fdd = open(argv[2],O_WRONLY|O_CREAT,0600);
  close (0);
  dup(p[0]);
  read(p[0],&size,4);
  buff=malloc(size);
  printf("size:%d\n",size);
  read(p[0],buff,size);
  printf("buff:\n%s",buff);
  write(fdd,buff,size);
 }
}
