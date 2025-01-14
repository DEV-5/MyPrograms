//DATE:4-11-16
//input two strings and insert second string in a given  position in the first string
#include<stdio.h>
#include<string.h>
#define s 20
void input(char *s1,char *s2,int pos);

int main()
{
int pos;
char s1[2*s],s2[s],temp[s];
input(s1,s2,pos);
 temp[0]=0;
 printf("\n temp:%s>",temp);
 if(pos>strlen(s1))
    strcat(s1,s2);
 else
 {          
  strcpy(temp,s1+pos);
  strcpy(s1+pos,s2);
  strcat(s1,temp);
 }
 printf("s1=%s,s2=%s,temp=%sEND\n",s1,s2,temp);
 return 0;
}
 
  void input(char *s1,char *s2,int pos)
{
printf("\nplease enter a string :");
fgets(s1,sizeof(s1),stdin);
s1[sizeof(s1)-1]=0;
printf("\ns1:%s:",s1);
printf("\nplease enter a string :");
fgets(s2,sizeof(s2),stdin);
s2[sizeof(s2)-1]=0;
printf("\ns2:%s>",s2);
printf("\nplease enter a the position where the string 2 is to be inserted: ");
scanf("%d",&pos);
return ;
}
