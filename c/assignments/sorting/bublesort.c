#include<stdio.h>
//date:20-3-17
#define no 7
void swap(int*,int*);
void printarray(int*a);
void bubblesort(int a[])//elements each
{
 int i,j;
  for(i=0;i<no;i++) 
   for(j=0;j<no-i-1;j++)
   if(a[j]>a[j+1])
    swap(a+j,a+j+1);
// printarray(a);
}

void swap(int *a,int *b)
{
 int temp=*a;
  *a=*b;
  *b=temp;
}
void printarray(int*a)
{
 for(int i=0;i<no;i++)
	 printf(" %d",a[i]);
 printf("\n");
}

int main()
{
 int arr[]={1,23,76,3,56,8,53};
 printarray(arr);
  bubblesort(arr);
 printarray(arr);
}
