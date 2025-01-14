
//DATE:21-8-18
//Purpose: application to test usage of memmove memcopy strcopy strncpy
#include<stdio.h>
#include<string.h>

int main()
{
 char thistr[] ="levelground";
 char temp[6]="oooooo";
 printf("temp = %s\n",temp);
 printf("thistr = %s\n",thistr);
 strncpy(temp,thistr,5);    
 printf("temp = %s\n",temp);
 memmove(thistr,thistr+5,6);
 memmove(thistr+6,temp,5);
 printf("thistr = %s\n",thistr);
 return 0;

}

