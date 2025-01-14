
//DATE:18-11-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* search_replace(char *buf,char** argv);

 int main(int argc,char** argv)
{
 int cnt,i=0;
 FILE *fp,f1;
 char *buf,ch;
 if(argc!=5 && argc!=4)
 {
  printf(" \nERROR wrong type argument was supplied");
  return 0;
 }
  if(argc==5)
 {
  printf("\n argv[4]=%s",argv[4]);
  argv[3][strlen(argv[3])]=' ';
  printf("\n strcat: %s",argv[3]);
 }
 fp=fopen(argv[1],"r");
 if(fp==NULL){printf("\n the source file does'nt exist\n");return 0;}
 fseek(fp,0,2);
 cnt= ftell(fp);
 rewind(fp);
 //fseek(fp,0,0);
 buf=calloc(1,cnt+1);
 printf("\n checkpoint 1\n");
 while((ch=fgetc(fp))!=EOF)
   buf[i++]=ch;
 fclose(fp);
 printf("\n 1.:%s:\n\n",buf);
 buf = search_replace(buf,argv);
 printf("\n checkpoint 2\n");
 printf("\n 2.:%s:\n",buf);
 printf(" \n the size of the file is %lu and count is%d\n",sizeof(f1),cnt);
}

 char* search_replace(char *buf,char**argv)
{
 char *p;
 int cnt,dif = strlen(argv[3])-strlen(argv[2]);
 for(p=buf;p=strstr(p,argv[2]);p=p+strlen(argv[2]))
  {
   printf("before int <%c>",p[-1]);
   printf("after int<%c>",p[strlen(argv[2])]);
  if(*(p-1)==' '||*(p-1)=='('||*(p-1)==')'||*(p-1)=='\''||*(p-1)=='\"'||*(p-1)==']'||*(p+1)=='\n');
  if(*(p+strlen(argv[2]))==' '||*(p+strlen(argv[2]))=='('||*(p+strlen(argv[2]))==')'||*(p+strlen(argv[2]))=='\''||*(p+strlen(argv[2]))=='\"'||*(p+strlen(argv[2]))==']'||*(p+strlen(argv[2]))=='\n')
          cnt++;

  printf(" cnt=%d ",cnt);
 }
 buf= realloc(buf,strlen(buf)+(dif*cnt)+1);
 buf[strlen(buf)]=0;
 for(p=buf;p=strstr(p,argv[2]);p=p+strlen(argv[3]))
 {
  printf("\n<<%s>>",buf);
  if(*(p-1)==' '||*(p-1)=='('||*(p-1)==')'||*(p-1)=='\''||*(p-1)=='\"'||*(p-1)==']'||*(p+1)=='\n');
   if(*(p+strlen(argv[2]))==' '||*(p+strlen(argv[2]))=='('||*(p+strlen(argv[2]))==')'||*(p+strlen(argv[2]))=='\''||*(p+strlen(argv[2]))=='\"'||*(p+strlen(argv[2]))==']'||*(p+strlen(argv[2]))=='\n')
   { 
     memmove(p+dif,p,strlen(p)+1);
     memmove(p,argv[3],strlen(argv[3]));
   }
  printf("\n<<%s>>\n",buf);
 }
  return buf;
}

/* char* new_replace(char*buf,char **argv)
{
 char *p;
 int i;
 for(p=buf;*p!=EOF;p++)
 {
  //if(*p!=' '&&*p!='('&&*p!=")"&&*p!="_"&&(*p>'9'||*p<'0'))
  //if(!((*(p+1)>='a'&&*(p+1)<='z')||(*(p+1)>='A'&&*(p+1)<='Z')))
  if((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z')) 
    i++;
  
  if(i==3)
  {  
   if(*(p+1)==' '||*(p+1)=='('||*(p+1)==')'||*(p+1)=='\''||*(p+1)=='\"'||*(p+1)==']')
   printf("\n ");
   i=0;
   p++;
  }
 }
 return p;
}*/
