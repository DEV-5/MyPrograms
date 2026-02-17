
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
 void fn (int n)
{
while(1){}
wait(0);
 printf("the child is dead\n");
}
 int main()
{
 int no;
 if(fork()==0)
 {
  printf("\n in child1:%d it's parents pid is:%d\n",getpid(),getppid());
  scanf("%d",&no);
  printf("\nyou have entered: %d\n",no);
  exit(0);
 }
 else
 {
  struct sigaction t;
  t.sa_handler= fn;
  sigaction(SIGCHLD,&t,NULL);
  printf("hello from the parent\n");
  pause();
 // printf("this is data to be sent to the buffer\n");
 }
 return 0;	
}
