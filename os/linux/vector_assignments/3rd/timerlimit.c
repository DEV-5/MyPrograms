
//DATE:22-12-16
#include<stdlib.h>
#include<stdio.h>
#include<sys/resource.h>
#include<signal.h>
void t(int n)
{
 printf("interupt no %d has occured \n",n);
 exit(0);
}
int main()
{
 signal(SIGXCPU,t);
 struct rlimit v;
 if(getrlimit(RLIMIT_CPU,&v)==-1)
  perror("getrlimit cpu:");
 else
 { 
  printf("%d %d \n",(int)v.rlim_cur,(int)v.rlim_max);
  v.rlim_cur=3;
  v.rlim_max=6;
  setrlimit(RLIMIT_CPU,&v);
  printf("%d %d \n",(int)v.rlim_cur,(int)v.rlim_max);
 }
 while(1);
}
