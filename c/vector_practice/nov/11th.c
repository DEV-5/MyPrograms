//DATE: 11-11-16

#include<stdio.h>
 int main()
{
        int a[2][3][4]={{{1}}};
        int ***p=a;
        printf("\n\n %u %u %u \n",a,a+1,*a+1);
        printf("\n\n %u %u %u \n",p,p+1,*p+1);
        return 0;
}
