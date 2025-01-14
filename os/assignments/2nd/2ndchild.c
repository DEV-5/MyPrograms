
//DATE:21-12-16
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

 int main()
{
 int v=0,pid;
// printf("in parent:%d it's parent is:%d\n",getpid(),getppid());
 if(fork()==0)
 {
  srand(getpid());
  printf("in child1:%d it's parent is:%d\n",getpid(),getppid());
  sleep(1+rand()%10);
  printf("child1 is exiting it's pid is:%d it's parent is:%d\n",getpid(),getppid());
  exit(1);
 }
 else if(fork()==0)
 {
  pid=getpid();
  srand(getpid());
  printf("in child2:%d it's parent is:%d\n",getpid(),getppid());
  sleep(1+rand()%10);
  printf("child2 is exiting it's pid is:%d it's parent is:%d\n",getpid(),getppid());
  exit(2);
 }
  else if(fork()==0)
 {
  srand(getpid());
  printf("in child3:%d it's parent is:%d\n",getpid(),getppid());
  sleep(1+rand()%10);
  printf("child3 is exiting it's pid is:%d it's parent is:%d\n",getpid(),getppid());
  exit(3);
 }

 else
 {
  //srand(getpid());
  printf("in parent:%d it's parent is:%d\n",getpid(),getppid());
 // sleep(1+rand()%10);
  while(v!=2) 
  {
  wait(&v);
  v>>=8;
  }
   	  
  // if(v==2)break; 
  printf("parent is exiting it's pid is:%d it's parent is:%d\n",getpid(),getppid());
  exit(0);
 }
}

