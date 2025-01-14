//to be compiled alongside other static.c
#include <stdio.h>
//#include <static.h>

extern int s_var;
int main()
{
    printf("The value of variable declared in the static.c is %d \n",s_var);
    printf("the sum of 5 and 14 is %d \n",adder(5,14));
}
