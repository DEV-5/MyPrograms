//DATE:17-11-16
#include<stdio.h>
#include<stdlib.h>

 int main(int argc,char ** argv)
{
 int cnt;
 FILE *fp;
 char ch,*buff=0;
 if(argc!=3){printf(" invalid arguments supplied ");return 0;}
 
 printf(" source: %s\n",argv[2]);
 printf(" target: %s\n",argv[1]);
 
 fp=fopen(argv[2],"r");
 if(fp==NULL){printf("\n Sorry the source file does not exist\n");return 0;}
 while((ch=getc(fp))!=EOF)
  cnt++;
 fclose(fp);
 buff=realloc(buff,cnt);
 cnt=0;
 fp=fopen(argv[2],"r");
 while((ch=fgetc(fp))!=EOF)
     buff[cnt++]=ch;
    buff[cnt-1]=0;
 printf("1.:%s: \n",buff);
 fclose(fp);
 fp=fopen(argv[1],"r");
 printf("checkpoint1 \n");
 if(fp!=NULL)
 { 
  printf("\n The file \"%s\" already exist \n\tTo overwrite it press o to overwrite it or press any other key to abort copy operation: \n  ",argv[1]);
  if(getchar()!='o') 
  { 
   fclose(fp);
   return 0;
  }
  fclose(fp);
 }
 fp=fopen(argv[1],"w");
 printf("checkpoint2 \n");
 for(cnt=0;buff[cnt];cnt++)
 fputc(buff[cnt],fp); 
 fclose(fp);
 printf("checkpoint3 \n");
 return 0;
}
