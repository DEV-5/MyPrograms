//DATE:2-11-16
//Purpose: generate a random word and find the no of vowels in the string.
#define s 20
#include<stdlib.h>
#include<unistd.h>
int system(const char*(clear));
int printf(const char*,...);
int scanf(const char*,...);

void vowel_check(char ar[]);
void insert(char al[]);
void print(char al[]);

int main()
{
     int i,j,ch=0;
     char al[s];
     system("clear");
     srand(getpid());
     insert(al);
     print(al);
     vowel_check(al);
     return 0;
}


void vowel_check(char ar[])
{
 int i,j,count;
 char vow[]="aeiou";
 for(i=0,count=0;i<s;i++)
 {
  for(j=0;vow[j];j++)
  {
   if(ar[i]==vow[j])       
    count++;
  }
 }
  printf("\nThe no of vowels in the array is %d\n",count);
}
 
 void insert(char al[])
{
   int ch,i,j;
   printf("please enter 0 to get uppercase random characters or press any other key to get lower case random characters: ");
   scanf("%d",&ch);
   if(ch!=0) ch=1;
   for(i=0;i<s;i++)
   {       
    al[i] =rand()%26+65+(32*ch);
     for(j=i-1;j>=0;j--)
     {
       if(al[i]==al[j])
       {
        i--;
        break;
       }
     }      
   }
}

 void print(char al[])
{
   int i;
   for(i=0;i<s;i++)
      printf("%c ,",al[i]);
   printf("\n");
   for(i=0;i<s;i++)
      printf("%-2d,",i);
}








