
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
  printf("inside parent:%d and its parent is:%d\n",getpid(),getppid());
  close(1);
  dup(p[1]);
  execlp("nm","nm",argv[1],NULL);
 }
 else 
 {
  printf("inside child:%d and its parent is:%d\n",getpid(),getppid());
  close (0);
  dup(p[0]);
  execlp("grep","grep",argv[2],NULL);
 }
}
