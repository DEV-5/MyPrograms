//DATE:21-12-16

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void test(int n)
{
 printf("Interupt from signal no %d \n",n);
 while(1);
}
int main()
{
 //signal(SIGHUP,SIG_IGN);
 signal(SIGINT,test);
 printf("\n In process pi:%d an it parent is:%d \n",getpid(),getppid());
 while(1);
}
