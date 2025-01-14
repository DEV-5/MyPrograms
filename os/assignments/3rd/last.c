
//DATE:26-12-16
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
 int choice;
 printf("this a sigcatch program \n");
 if(fork()==0)
 {
  printf("child1: pid=%d\n please enter an alphabet: ",getpid());
  scanf("%d",&choice);
  printf("you have entered the number %d",choice);
  printf("please enter second choice: ");
  printf("you have entered the number %d",choice);
  scanf("%d",&choice);
  while(1);
  exit(0);
 }
 else wait(NULL);
}
