
//display  the binary equivalent of the decimal number entered

#include<stdio.h>
 
  int main ()
 {
  int n,a;	 
  a = sizeof(int)*8-1;
  printf("please enter a number :  ");
  scanf("%d",&n);
  
 TOPI:
   if(a>=0)
  { 
   printf("%d",1&(n>>a));
   a--;
   goto TOPI;
  }

   return 0;
 }

  
 
