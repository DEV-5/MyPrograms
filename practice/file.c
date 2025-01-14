#pragma pack(1)
#include<stdio.h>
typedef struct 
{
 int i;
 char ch;
}hrs;

enum num
{
 one=1,two,three,four
};
typedef enum num num;

int main()
{
 hrs new={12,'A'};
 num hello;
 printf("%d\n",hello);
 printf("%d\n",sizeof(two));
 printf("i=%d and ch=%c\n",new.i,new.ch);
 printf("the size of the data is %d",sizeof(hrs));
}
