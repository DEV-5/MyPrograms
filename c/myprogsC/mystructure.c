/*
 * Author: Vasudev.m
 * Date:14-02-2020
 * purpose: Basic program test to structure
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct mystruct{
    int a;
    char b;
    int c;
    char d;
    };


int main()
{
    struct mystruct obj1;
    struct mystruct *obj2 = malloc(12);
    printf("The size of mystruct object is %lu\n",sizeof(obj1));
    obj2->a = 12;
    obj2->b = 'f';
    obj2->c = 34;
    obj2->d = 'G';
    printf("The obj2 a=%d b=%c c=%d d=%c \n",obj2->a,obj2->b,obj2->c,obj2->d);
}
