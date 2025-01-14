//#pragma pack(1)
#include<stdio.h>

typedef struct
{
 char s;
 char ch;
 int a;
}newstruct;

int main()
{
 printf("%c\n",*("alfa"+1));
 printf("the size of new struct: %d\n",sizeof(newstruct));
}
