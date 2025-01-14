#include<stdio.h>

int main()
{
    int a= 2;
    
    switch(a)
    {
        case 1:
            printf("Inside case 1\n");
            break;
        case 2:
        {
            int b = 134;
            printf("The value of b is %d\n",b);
            //break;//removing break will cause it to execute rest of the cases
        }

        case 3:
            printf("Inside case 3\n");
        default:
            printf("Inside Default case\n");
    }
}
