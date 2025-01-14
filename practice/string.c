
#include<stdio.h>
 int main ()
{
 char ch[11]="this is it";
 //putc(ch[9],stdout);
 puts(ch);
 printf("%d size is %d",ch,sizeof(ch));
 ch=ch+1;
 putc(ch[1],stdout);
}
