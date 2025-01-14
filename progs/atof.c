//DATE:20-12-16

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 int deldot(char* st)
{
 int i=-1;
 while(*st)
 {
  if(i)i++;
  if(*st=='.')
  {
   i=1;
   memmove(st,st+1,strlen(st+1)+1);
  }
  st++;
 }
 return i;
}

int power(int dot)
{
 int res=1;
 while(dot--)
 {
  res*=10;
 }
 return res;
}

 float a2f(char* str)
{
 float fl;
 int dot,nu;
 char temp[30],*st=temp;
 strcpy(temp,str);
 dot=deldot(temp);
 while(*st)
 {
  if((*st)<48||(*st)>57)
  {
   printf("\n the data you have entered is incorrect\n");
   exit(0);  
  }
  st++;
 }
 printf("|%s|\n",temp);
  nu=atoi(str);
  fl = (float)atoi(str);
 printf("|%f|\n",fl);
  printf("dot before:%d\n",dot);
  dot=power(dot);
  printf("dot after:%d\n",dot);
  fl/=(float)dot;
 
 return fl;
}


int  main()
{
 char str[30];
 float res;
 printf("please enter a float: "); 
 scanf("%s",str);
 res=a2f(str);
 printf("\n you have entered<%f>\n",res);
}
