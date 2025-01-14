#include<stdio.h>
//date:20-3-17
#define no 7
void swap(int*,int*);
void printarray(int*a);
void selectionsort(int a[])//elements each
{
 int i,j;
  for(i=0;i<no;i++) 
   for(j=i+1;j<no;j++)
   if(a[i]>a[j])
    swap(a+i,a+j);
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
  selectionsort(arr);
 printarray(arr);
}
