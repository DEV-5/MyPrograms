//to be compiled alongside static_main
//#define <stdio.h>

#include<stdio.h>

int s_var =1000;

int adder(int op1,int op2)
{
    int a = 1024;
    printf(" the value of a is %d",a^(1<<10));
    return op1+op2;
    //printf("dummy")
    //return 0;
}



