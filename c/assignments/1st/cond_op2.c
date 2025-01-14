
//date:5-10-2016
//conditional operator based assignment
//enter two number and find out the relationship between the two numbers
 
#include<stdio.h>
#include<stdlib.h>
  int main ()
 { 
  int q,b;
  system("clear");
  scanf("%d %d",&q,&b);
  (q==b)?printf("\n they are equal\n") : (q>b)?printf("\nq is greater than b\n") : printf("\nb is greater than q\n");
  return 0;
 }
