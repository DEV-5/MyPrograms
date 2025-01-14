//DATE:4-11-16
//char st[40]=" mon k   ey  ";
//purpose: to remove any extra blank spaces present.
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
int printf(const char*,...);
int scanf(const char*,...);
#include<string.h>
char *gets(char*);
void del_space(char* sp);
int main()
{
 //char st[40]=" mon k   ey  ";
    char st[40]="    m   o    n   k    ey  ";
 printf("\n please enter a sentence: ");
 fgets(st,40,stdin);
 st[strlen(st)-1]=0;
 //puts(st);
 wait(0);
 printf("%s\n",st);
 del_space(st);
 printf("%s\n",st);
 scanf("%s",&st);//adding  for debuggiing purpose
 //puts(st);
 return 0;
}

 void del_space(char* sp)
{
  char *p;
  for(p=sp;p = strstr(p,"  ");p++)
  {
    memmove(p,p+1,strlen(p+1)+1);
    p--;
  }
  return;
}
