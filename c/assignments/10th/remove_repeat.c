//DATE:4-11-16
//program to delete repeating characters
#include<stdio.h>
int printf(const char*,...);
int scanf(const char*,...);
#include<string.h>
char *gets(char*);
 void del_repeats(char * st);
int main()
{
 char st[40]="    m   o    n   k    ey  ";
 printf("\n please enter a sentence: ");
 fgets(st,40,stdin);
 st[strlen(st)-1]=0;
 printf("%s\n",st);
 del_repeats(st);
 printf("%s\n",st);
 return 0;
}
 
 void del_repeats(char * st)
{
  int a;
  for(a=0;*st;st++)  
   if((a>>*st)&1)
   {
    memmove(st,st+1,strlen(st+1)+1);
    st--;
   }
   else
           a|=(1<<*st);
 return ;        
}
