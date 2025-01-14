
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int a,b,sum;
 if(fork()==0)
 {
  printf("please enter two numbers: ");
  scanf("%d %d",&a,&b);
  exit(a+b);
 }
 else
 {
  wait(&sum);
  printf("\n The sum of the entered numbers is:%d\n",sum>>8);
  return 0;
 }
}

