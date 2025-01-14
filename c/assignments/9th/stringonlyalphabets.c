//DATE:4-11-16
//program to enter a string and remove any character other than alphabets
#include<stdio.h>
#include<string.h>
#define s 20
int main()
{
int pos;
char str[s];
printf("\nplease enter a string :");
fgets(str,sizeof(str),stdin);
str[sizeof(str)-1]=0;
for(pos=0;str[pos];pos++)
        if(!(((str[pos]>='a')&&(str[pos]<='z'))||((str[pos]>='A')&&(str[pos]<='Z'))))
                memmove(str+pos,str+pos+1,strlen(str+pos+1)+1);
printf("\n str:%s\n",str);
return 0;
}
