//obj: mergesort algorithm without Recursion
//Author: Vasudev
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int * arr;
 printf("please enter more than one integer list which need to be sorted ");
 arr = calloc(sizeof(int),3);
 for(int i =0; i<3;i++)
 {
  scanf("%d",(arr+i));
  printf("The value entered is : %d\n",*(arr+i));	  
 }
}
