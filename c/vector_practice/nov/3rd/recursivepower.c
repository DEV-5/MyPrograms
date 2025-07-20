#include<stdio.h>
int power(int,int);
int main ()
{
  int no,pow;
  printf("please enter a number and its power: ");
  scanf("%d%d",&no,&pow);
  no=power(no,pow);
  printf("the ans is %d",no);
  return 0;
}
 int power (int no,int pow)
{
        if(pow==0)
            return 1;
 return no*power(no,pow-1);
}
