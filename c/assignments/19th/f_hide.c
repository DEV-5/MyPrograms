
//DATE:20-11-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int if_found(char*p,int l)
{
  if(*(p-1)==' '||*(p-1)=='('||*(p-1)=='='||*(p-1)=='\''||*(p-1)=='\"'||*(p-1)=='['||*(p+1)=='\n'||*(p+1)==','||*(p+1)==';'||*(p+1)=='*'||*(p+1)=='+'||*(p+1)=='-'||*(p+1)=='/');
   if(*(p+l)==' '||*(p+l)=='('||*(p+l)==')'||*(p+l)=='\''||*(p+l)=='\"'||*(p+l)==']'||*(p+l)=='\n'||*(p+l)=='*'||*(p+l)==';'||*(p+l)==','||*(p+l)=='='||*(p+l)=='+'||*(p+l)=='-'||*(p+l)=='/')
     return 1;
  return 0;
}

int main(int argc,char** argv)
{
 int cnt,i=0;
 FILE *fp,f1;
 char line[80],ch,*p;
 if(argc!=3)
 {
  printf(" \nERROR wrong type argument was supplied");
  return 0;
 }
 fp=fopen(argv[1],"r+");
 if(fp==NULL){printf("\n the source file does'nt exist\n");return 0;}
 fseek(fp,0,2);
 cnt= ftell(fp);
 rewind(fp);
 printf("\n checkpoint 1\n");
 while(fgets(line,80,fp))
  if(p=strstr(line,argv[2]))
  if(if_found(p,strlen(argv[2])))  
  {
   memset(p,'$',strlen(argv[2]));
   fseek(fp,-1*strlen(line),1);
   fputs(line,fp);
  }
 fclose(fp);
 printf("\n checkpoint 2\n");
 printf(" \n the size of the file is %lu and count is%d\n",sizeof(f1),cnt);
}

