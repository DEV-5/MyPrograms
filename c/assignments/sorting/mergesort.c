#include<stdio.h>
//date:20-3-17
#define no 7
void swap(int*,int*);
void printarray(int*a);
int* join(int[],int,int[],int);

int*  mergesort(int a[],int lw,int up)
{
    int *b,*c,sizeb,sizec;
    if (up>lw+1)
    {
        b = mergesort(a,lw,(lw+up)/2);
        c = mergesort(a,(lw+up)/2+1,up);
        sizeb = (lw+up)/2;
        sizec = lw+up - sizeb;
        join(b,sizeb,c,sizec);
        printf("a");
    }
    else if(up ==lw+1) 
            if(a[up]>=a[lw])
                printf("please");
            
    else//lw=up
        return a; 
    
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

int* join(int a[],int sizea,int b[],int sizeb)
{
    int  i;
    for(i=0;i<sizea;i++)
    {

    }
}

int main()
{
    int arr[]={1,23,76,3,56,8,53};
    printarray(arr);
    mergesort(arr,0,no);
    printarray(arr);
    puts("-------------------------------------");
    int arr1[]={12,0,90,78,69,39,99};
    printarray(arr1);
    mergesort(arr1,0,no);
    printarray(arr1);
}
