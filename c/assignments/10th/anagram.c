//DATE:4-11-16
//program to input two strings and  verify  that they are anagrams of one other.

#include<stdio.h>
#include<string.h>
int system(const char*(clear));

char *gets(char*);
int del_sm(char* sp,char*sm);
void read(char *st,char *sm);
int if_anagram(char*,char* );
void sort(char *);
void del_space(char* );
void sel_sort(char*a,int n);

int main()
{
 int count;
 char st[40],sm[10];
 system("clear");
 read(st,sm);
 printf("%s\n",st);
 printf("%s\n",sm);
if( if_anagram(st,sm))
        printf("\nthey are anagrams\n");
else
        printf("\nthey are not anagrams\n");
 printf("\n%s\n",st);
 printf("%s\n",sm);
 return 0;
}

 int if_anagram(char* st,char* sm )
{
/*Make a copy of the string variables.
 *remove any space present in the copy of the strings. 
 *sort the string and then compare them.
 */
 char w1[40],w2[40];
 strcpy(w1,st);
 strcpy(w2,sm);
 del_space(w1);
 del_space(w2);
 if(strlen(w1)!=strlen(w2))
  return  0;
 sel_sort(w1,strlen(w1));
 sel_sort(w2,strlen(w2));
 if(~strcmp(w1,w2))
         return 1;
 else 
         return 0;
}

 void read(char *st,char *sm)
{
 printf("\n please enter a string1: ");
 fgets(st,40,stdin);
 st[strlen(st)-1]=0;
 printf("\n please enter a string2: ");
 fgets(sm,40,stdin);
 sm[strlen(sm)-1]=0;
 printf("\n string s2 is %s\n",sm);
}

 void del_space(char* sp)
{
  char *p;
  for(p=sp;p = strstr(p," ");p++)
  {
    memmove(p,p+1,strlen(p+1)+1);
    p--;
  }
  printf("\n in del_space the final value is :%s:",sp);
  return;
}

  void sel_sort(char *a,int n)
 {
  for(int k=0;k<n-1;k++)
  {	  
    for(int i=k;i<n;i++)
   {
     if(a[i]<a[k])
    {
     a[k]+=a[i];
     a[i]=a[k] - a[i];
     a[k]-=a[i];  
    }	    
   }
  } 
  printf("\n in sel_sort the final value is :%s:",a);
  return ;
 }

