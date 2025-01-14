#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stu{
                   int roll ;
                   char name[20];
                   float marks;
                   struct stu *link;
                  }STUDENT;
