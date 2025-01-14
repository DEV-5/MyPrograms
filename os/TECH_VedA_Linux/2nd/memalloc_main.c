#include<stdio.h>

int main()
{
    int a;
    int b;
    int c;

    printf("inside main \n");
    printf("The address of a is %p and b is %p and c is %p \n",&a,&b,&c);
    a = 0;
    b = 1;
    c = 2;
    return 0;
}
