//DATE : 8th Aug 2020
#include<stdio.h>

static int i;
static int i = 27;
static int i;//This line makes no difference.
//i = 90; //This line will result in redefinition error 

int main()
{
    static int i; 
    //uncommenting above line will cause the local i to take precedence & i will be printed as 0
    printf("value of  i = %d\n",i); 
}
