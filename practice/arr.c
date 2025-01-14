
#include<stdio.h>
int main()
{
 char s[4]="man";
 int i;
 for(i=0;s[i];i++)
  printf("%c %c %c %c \n",s[i],*(s+i),*(i+s),i[s]);
}
