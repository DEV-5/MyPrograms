
//DATE:18-11-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void search_replace(char *buf);
int main(int argc,char** argv)
{
 int cnt,i=0;
 FILE *fp,f1;
 char *buf,ch;
 if(argc!=2)
 {
  printf(" \nERROR wrong type argument was supplied");
  return 0;
 }
 fp=fopen(argv[1],"r");
 if(fp==NULL){printf("\n the source file does'nt exist\n");return 0;}
 fseek(fp,0,2);
 cnt= ftell(fp);
 //rewind(fp);
 fseek(fp,0,0);
 buf=calloc(1,cnt+1);
 printf("\n checkpoint 1\n");
 while((ch=fgetc(fp))!=EOF)
   buf[i++]=ch;
 fclose(fp);
 printf("\n 1.:%s:",buf);
 search_replace(buf);
 printf("\n checkpoint 2\n");
 printf("\n 2.:%s:",buf);
 printf(" \n the size of the file is %lu and count is%d",sizeof(f1),cnt);
}

void search_replace(char *buf)
{
 char key[4]="123",yek[4]="321",*p;
  for(p=buf;p=strstr(p,key);)
         memmove(p,yek,strlen(key));
}
