
//DATE:18-11-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 void print(FILE*p)
{
 char ch;
 int i;
 for(i=0;i<4;ch=fgetc(p))
 {
  if(ch==EOF)   { printf("\n NO OF LINES ARE %d",i); return ;}
  if(ch=='\n') i++;
  
  if(i==4)
    do{
       printf("%c",ch);  
       ch=fgetc(p);
      }while(ch!='\n'&&ch!=EOF);      
  } 
}

 int main(int argc,char** argv)
{
 FILE *fp;
 if(argc!=2)
 {
  printf(" \nERROR wrong type argument was supplied");
  return 0;
 }
 fp=fopen(argv[1],"r");
 if(fp==NULL){printf("\n the source file does'nt exist\n");return 0;}
 printf("\n checkpoint 1:\n");
 print(fp);
 printf("\n checkpoint 2\n");
}


