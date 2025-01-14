//DATE: 11th Aug 2020
#include<stdio.h>
int main()
{
    int a =5,b=6;
    const int* var1 = &a;
    int* const var2 = &a;
    int const* var3 = &a;
    
    //change addresses
    var1 =&b;
    //var2 =&b; //assignment of read-only variable 'var2'
    var3 =&b;

    //change value at adresses
    //*var1 = 7;//assignment of read-only location '*var1'
    *var2 = 7;
    //*var3 = 7;//assignment of read-only location '*var3'
    
    printf("Value @var1 =%d and var1 =%p \n",*var1,var1);
    printf("Value @var2 =%d and var2 =%p \n",*var2,var2);
    printf("Value @var3 =%d and var3 =%p \n",*var3,var3);
}
