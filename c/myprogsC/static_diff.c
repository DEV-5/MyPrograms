#include<stdio.h>

void call(int,int);
  int main ()
 { 
 int a=0;
 int b=0;
 a=b+5;
 printf("\n");
  for(int i=0;i<10;i++)
  {
    call(a,b);
  }
   printf("the value of a = %d and b=%d\n\n",a,b);
   return 0;
 }
  
     void call(int a,int b)
  {
      static int c=3;
      a+=10;
      c+=10;
      printf(" fn values of a=%d and c=%d\n",a,c);
  }
