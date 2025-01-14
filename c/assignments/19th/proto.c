
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* itoa(int n)
{
 int i=0,size;
 char *num=0,*rev;
 while(n)
{
  num=realloc(num,i+1);
  num[i]=48+(n%10);
  n/=10;
  i++;
}
rev=calloc(0,strlen(num)+1);
for(i=0;i<strlen(num);i++)
 rev[i]=num[strlen(num)-i-1];
 return rev;
}

 int main()
{
 int n=1234;
 char *r;
 printf("\nnumber<%s>",r=itoa(n));
}
