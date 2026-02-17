
//DATE: 21-12-16
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 int main()
{
 if(fork()!=0)
 {
  srand(getpid());
  printf("In parent: %d it's parent is:%d \n",getpid(),getppid());
  sleep(1+rand()%10);
  wait(NULL);
  printf("parent exiting it'spid: %d it's parent is:%d \n",getpid(),getppid());
  exit(0);
 }

 else if(fork()!=0)
 {
  srand(getpid());
  printf("In child1: %d it's parent is:%d \n",getpid(),getppid());
  sleep(1+rand()%10);
  wait(NULL);
  printf("child1 exiting it'spid: %d it's parent is:%d \n",getpid(),getppid());
  exit(1);
 }

 else if(fork()!=0)
 {
  srand(getpid());
  printf("In child2: %d it's parent is:%d \n",getpid(),getppid());
  sleep(1+rand()%10);
  wait(NULL);
  printf("child2 exiting it'spid: %d it's parent is:%d \n",getpid(),getppid());
  exit(2);
 }
 else
 {
  srand(getpid());
  printf("In child3: %d it's parent is:%d \n",getpid(),getppid());
  sleep(1+rand()%10);
  wait(NULL);
  printf("child3 exiting it'spid: %d it's parent is:%d \n",getpid(),getppid());
  exit(3);
 }
 
}
