#include<stdio.h>

int main()
{
    int i=1,j;
    printf("Value of i is %d",i);
    scanf("values of i are");
    
    {//scope of nine is local to this block
        int nine = 10;
        printf("the value of nine is %d\n",nine);
    }
    //printf("the value of nine is %d\n",nine); //invalid as nine is not declared 
    
    printf("the value of i is %d\n",i);
    for(j=0;j<1;j++)
    {
     int i =12;
     printf("the value of i is %d\n",i);

    }
     printf("the value of i is %d\n",i);
     //printf("the value of g is %d\n",g); //invalid as g is not declared 
    return 0;
}
