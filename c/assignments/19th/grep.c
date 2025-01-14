
//DATE:19-11-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int if_found(char *found,int l);
int main(int argc,char**argv)
{
 FILE *fp;
 char buf[80],*found;
 int i=0;
 if(argc!=3){printf("\nERROR the incorrect arguments ");return 0;}
 fp=fopen(argv[1],"r+");
 if(fp==NULL){printf("\n The source files does not exist\n");return 0;}
 system("clear");
  while(fgets(buf,80,fp))
 {i++;
  if(found=strstr(buf,argv[2]))
  if(if_found(found,strlen(argv[2])))
    printf("%s",buf);      
 }
  printf("checkpoint%d\n",i);
  return 0;
}

 int if_found(char*p,int l)
{
  if(*(p-1)==' '||*(p-1)=='('||*(p-1)=='='||*(p-1)=='\''||*(p-1)=='\"'||*(p-1)=='['||*(p+1)=='\n'||*(p+1)==','||*(p+1)==';'||*(p+1)=='*'||*(p+1)=='+'||*(p+1)=='-'||*(p+1)=='/');
   if(*(p+l)==' '||*(p+l)=='('||*(p+l)==')'||*(p+l)=='\''||*(p+l)=='\"'||*(p+l)==']'||*(p+l)=='\n'||*(p+l)=='*'||*(p+l)==';'||*(p+l)==','||*(p+l)=='='||*(p+l)=='+'||*(p+l)=='-'||*(p+l)=='/')
     return 1;
  return 0;
}
