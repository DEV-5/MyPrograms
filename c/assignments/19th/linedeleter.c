
//DATE:22-11-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cnt;
void* deleter(char **p,int n1,int n2);
 
 int main(int argc,char** argv)
{
 char ch,**line,*pt,num[2][5]={"0","0"};
 FILE *fp;
 int i,j,num1,num2;
 if(argc!=3){printf("\n Incorrect arguments provided\n");return 0;}
 if(pt=strstr(argv[2],"-"))
 {
  memmove(num[0],argv[2],strlen(argv[2])-strlen(pt));
  memmove(num[1],pt+1,strlen(pt+1)+1);
  num1=atoi(num[0]);
  num2=atoi(num[1]);
  if(num1>num2)
  {
   num1+=num2;
   num2=num1-num2;
   num1-=num2;
  }
  num1--;num2--;
  printf("num1=%d\n",num1);
  printf("num2=%d\n",num2);
 }
 else
 {
  num1=num2=atoi(argv[2])-1;
 }
 if(num1<0||num2<0||num1+num2+1==0){printf("\n wrong index argument has been entered \n");return 0;}

 fp=fopen(argv[1],"r");
 if(fp==NULL){printf("sorry the source file does not exist");return 0;}
 
 line = realloc(0,sizeof(char *));
 for(i=0,j=0;(ch=fgetc(fp))!=EOF;) 
 {
  line[i]=realloc(line[i],(j+1));
  line[i][j++]=ch;  
 // printf("<%c>",line[i][j-1]);
  if(ch=='\n')
  {
   line[i][j]=0;
 //  printf("entry no%d",i+1);
   i++;
   line = realloc(line,sizeof(char *)*(i+1));
   j=0;
  } 
 }
 cnt=i;
 fclose(fp);
 if(cnt<num2+1||cnt<num1+1){printf("\n supplied line number value is greater than no of lines present in file(%d lines)\n",cnt);return 0;}
 for(i=0;i<cnt;i++)
  printf("%s",line[i]); 
 printf("\n count:%d\n",cnt);
 printf("\n copying sucessfull\n");
 line=deleter(line,num1,num2);
 printf("\n After sort :\n\n");
 for(i=0;i<cnt;i++)
  printf("%s",line[i]); 
//fp=fopen(argv[1],"w");
 //for(i=0;i<cnt;fputs(line[i],fp),i++);
}

 void* deleter(char **p,int n1,int n2)
{
 int i;
 //for(i=n1;i<=n2;i++)
 // size+=strledn(p[i]);
 for(i=0;i<=n2-n1;i++)
 free(p[i+n1]); 
 memmove(p+n1,p+n2+1,sizeof(char*)*(cnt-n2-1));
 p=realloc(p,(cnt-n2+n1-1)*sizeof(char*));
 cnt+=n1-n2-1;
        return p;
}
  
