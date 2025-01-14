//Remove additional Whitespace in the file mentioned as a commmand line 
//DATE:18-11-16
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void remove_extra(char *str)
{
 char *p;

   while(p=strstr(str,"  "))
   { memmove(p,p+1,strlen(p+1)+1);p--;}
 return;
}
 int main(int argc,char ** argv)
{
 int cnt;
 FILE *fp;
 char ch,*buff=0;
 if(argc!=2){printf(" invalid arguments supplied ");return 0;}
 
 printf(" source: %s\n",argv[1]);
 
 fp=fopen(argv[1],"r");
 if(fp==NULL){printf("\n Sorry the source file does not exist\n");return 0;}
 while((ch=getc(fp))!=EOF)
  cnt++;
 fclose(fp);
 buff=realloc(buff,cnt);
 cnt=0;
 fp=fopen(argv[1],"r");
 while((ch=fgetc(fp))!=EOF)
     buff[cnt++]=ch;
 fclose(fp);
    buff[cnt-1]=0;
 printf("before remove\n:%s:strlen=%lu \n",buff,strlen(buff));
   remove_extra(buff);
 printf("after remove\n:%s:strlen=%lu \n",buff,strlen(buff));
 fp=fopen(argv[1],"w");
 printf("checkpoint2 \n");
 for(cnt=0;buff[cnt];cnt++)
 fputc(buff[cnt],fp); 
 fclose(fp);
 printf("checkpoint3 \n");
 return 0;
}
