
//DATE:21-11-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 int noofword(char*p);
int main(int argc,char**argv)
{
 FILE *fp;
 char *p,*linebuf=0,ch;
 int lines,i,j,cha,words;
 if(argc!=3&&argc!=2){printf("\nERROR the incorrect arguments ");return 0;}
 fp=fopen(argv[1],"r+");
 if(fp==NULL){printf("\n The source files does not exist\n");return 0;}
 if(argc==3)
 if(!(p=strstr(argv[2],"-"))||(*(p+1)!='l'&&*(p+1)!='w'&&*(p+1)!='c'))
  {printf("\n the arguments are incorrectly supplied\n");return 0;}     
 system("clear");
 fseek(fp,0,2);
 cha=ftell(fp);
 rewind(fp);
 for(i=0,j=0,words=0;(ch=fgetc(fp))!=EOF;) 
 {
  linebuf=realloc(linebuf,(j+1));
  linebuf[j++]=ch;  
  if(ch=='\n')
  {
   words+=noofword(linebuf);
   printf(":%s:",linebuf);
   i++;
   free(linebuf);
   linebuf=0;
   //line = realloc(line,sizeof(char *)*(i+1));
   j=0;
  } 
 } 
 fclose(fp);
 lines=i;
 if(argc==2)
 printf("\n  Total char:%d lines:%d words:%d\n",cha,lines,words);
 else if(p=strstr(argv[2],"-"))
 { 
  if(*(p+1)=='l')
   printf("\n  Total lines:%d\n",lines);  
   else if(*(p+1)=='w')
    printf("\n  Total words:%d\n",words);
    else if(*(p+1)=='c')
     printf("\n  Total char:%d\n",cha);
 }
 printf("checkpoint2\n");
 /* while(fgets(buf,80,fp))
 {
  i++;
   if(isaword(found,strlen(argv[2])))
    printf("%s",buf);      
 }*/
 return 0;
}

 int noofword(char*p)
{
 int l,cnt,fi;
 for(cnt=0,fi=1;(*p!='\n'&&*p!='\0');p++,fi=0)
 { 
  printf("*p=%c,%d|",*p,cnt);
  if(*(p-1)==' '||*(p-1)=='('||*(p-1)=='='||*(p-1)=='\''||*(p-1)=='\"'||*(p-1)=='['||*(p+1)=='\n'||*(p+1)==','||*(p+1)==';'||*(p+1)=='*'||*(p+1)=='+'||*(p+1)=='-'||*(p+1)=='/');
  {
   for(l=1;1;l++)
   if(*(p+l)=='\0'||*(p+l)==' '||*(p+l)=='('||*(p+l)==')'||*(p+l)=='\''||*(p+l)=='\"'||*(p+l)==']'||*(p+l)=='\n'||*(p+l)=='*'||*(p+l)==';'||*(p+l)==','||*(p+l)=='='||*(p+l)=='+'||*(p+l)=='-'||*(p+l)=='/')
   {
    cnt++;
    p=p+l;  
    break;
   }
  }
 }
 return cnt;
}
