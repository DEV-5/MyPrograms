//Author: vasudev m
//Date: 31st March 2020
//purpose: bit set and clear operations in c

#include<stdio.h>

int main()
{
    unsigned char ch= 0xA0; 
    unsigned char ch2= 0x80;
    //clear 0x80 from ch
    printf("The value of ch = %u and ch after and op is %u\n",ch,ch&(~ch2));
}
