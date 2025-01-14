/*
 * Author: Vasudev M
 * Date: 17th March 2020
 * Purpose: Verify the working of bit field
 */

#include <stdio.h>

#define pragna pack 1

struct A1
{
    int sm1;
}a1;

typedef struct A2
{
    short int sm2;
}a2;
typedef struct A3
{
    char sm3;
}a3;

typedef struct A4
{
    int sm4_1;
    short sm4_2;
    char sm4_3;

}a4;

int main()
{
    int i =10;
    double d = 11.2;
    printf("\nThe size of char is %lu, short int is %lu, int is %lu, long int" 
            "is %lu, long long int is %lu,float is %lu and double is %lu\n",
            sizeof(char),sizeof(short int),sizeof(int),sizeof(long int),
            sizeof(long long int),sizeof(float),sizeof(double));
    printf("The size of structure A1 = %lu, A2 = %lu, A3 is %lu and A4 is %lu\n"
            ,sizeof(a1),sizeof(a2),sizeof(a3),sizeof(a4));        
    printf("print i(%%p)= %p, &i(%%p)= %p and &i(%%lu)= %lu\n",i,&i,&i);
    printf("i=%lf and d= %d\n",i,d);
    printf("i=%lf\n",i);
    printf("d= %d\n",d);
}
