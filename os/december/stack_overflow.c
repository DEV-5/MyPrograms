//DATE:14-12-16
#include<stdio.h>
#include<sys/resource.h>
void fn()
{
 static int i;
 char str[1000000];
 i++;
 if(i<=20)
	fn();
 printf("\n returning from \n");
 return;
}

int main()
{
 struct rlimit v;
 if(getrlimit(RLIMIT_STACK,&v)==-1)
  perror(" ");
 else 
  printf("\n %d %u \n",(int)v.rlim_cur,(unsigned int)v.rlim_max);
 v.rlim_cur=25000000;
 setrlimit(RLIMIT_STACK,&v);
 fn();
}
