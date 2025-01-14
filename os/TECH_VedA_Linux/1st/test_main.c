//Date: 28th Sept 2019
//main function 

#include<stdio.h>
#include "test_add.h"

int main()
{
    int a = 156;
    int b = 5;    
    printf("This is the main test function\n");
    printf("The sum of %d and %d is %d",a,b,addint(a,b));
    return 0;
}
