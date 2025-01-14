
#include<stdio.h>

int add(int,int);
double div(int,int);

int main()
{
 int a=43,b=3,sum=0;
 double res=0;
 printf("there is no spoon \n");
 sum=add(a,b);
 res=div(a,b);
 printf(" %d + %d= %d and %d / %d = %lf \n",a,b,sum,a,b,res);
}
