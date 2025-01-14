/*
 * Author: Vasudev M
 * Date: 10th March 2020
 * Purpose: Verify the working of bit field
 */

#include <stdio.h>

#define pragna pack 1

struct A1
{
    int sm1;
}a1; //size is 4

typedef struct A2
{
    short int sm2;
}a2; //size is 2

typedef struct A3
{
    char sm3;
}a3; //size is 1

typedef struct A4
{
    int sm4_1;
    short sm4_2;
    char sm4_3;

}a4; //size is 8

typedef struct A5
{
    int sm4_1:1;
    short sm4_2:1;
    char sm4_3:1;

}a5;//size is 4

typedef struct A6
{
    int sm4_1:1;
    short sm4_2;
    char sm4_3:1;

}a6;//size is 8

typedef struct A7
{
    int sm4_1:1;
    short sm4_2;
    char sm4_3:1;

}__attribute__ ((__packed__)) a7; //size is 4, alignment is ingnored as __packed__ is supplied

typedef struct A8
{
    int sm4_1:1;
    short sm4_2:15;
    char sm4_3:1;

}a8;//size is 8

typedef struct A9
{
    short int sm7_1:1;
    short int sm7_2:1;
    short int sm7_3:1;
    short int sm7_4:1;
    short int sm7_5:1;
    //short sm7_2:1;
    //char sm7_3:1;
    //char sm7_4:7;
    //short sm7_5:1;

}a9;//size is 2

typedef struct A10
{
    int sm7_1:1;
    short sm7_2:1;
    char sm7_3:1;
    char sm7_4:7;
    short sm7_5:1;
}a10;//size is 4

int main()
{
    int i =10;
    double d = 11.2;
    printf("\nThe size of char is %lu, short int is %lu, int is %lu, long int" 
            "is %lu, long long int is %lu,float is %lu and double is %lu\n",
            sizeof(char),sizeof(short int),sizeof(int),sizeof(long int),
            sizeof(long long int),sizeof(float),sizeof(double));
    printf("The size of structure A1 = %lu, A2 = %lu, A3 = %lu, A4 = %lu,"
            " A5 = %lu, A6 = %lu, A7 = %lu, A8 = %lu, A9 = %lu and A10 = %lu\n" \
            ,sizeof(a1),sizeof(a2),sizeof(a3),sizeof(a4),sizeof(a5),sizeof(a6),sizeof(a7),sizeof(a8),sizeof(a9),sizeof(a10));        
    printf("print i(%%p)= %p, &i(%%p)= %p and &i(%%lu)= %lu\n",i,&i,&i);
    printf("i=%lf and d= %d\n",i,d);
    printf("i=%lf\n",i);
    printf("d= %d\n",d);
}
