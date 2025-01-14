
//DATE:27-11-16
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt;

 void* filetobuf(char**buf,FILE *fp);
 int main(int argc,char** argv)
{
 FILE *fp;
 char**buf1,**buf2;
 int i,cnt1,cnt2,line;
 if(argc!=4){printf("\n incorrect no of arguments\n");return 0;}
 fp=fopen(argv[1],"r");
 line=atoi(argv[3]);
 if(line<0){printf("\n invalid index is supplied\n");return 0;}
 if(fp==NULL){printf("\n source file1 doesn't exist\n");return 0;}
 buf1=calloc(1,sizeof(char*));
 buf1=filetobuf(buf1,fp); 
 cnt1=cnt;
 if(cnt1<atoi(argv[3])){printf("\nincorrect index is supplied max line in file1 are%d \n",cnt);return 0;}
 fp=fopen(argv[2],"r");
 if(fp==NULL){printf("\n source file2 doesn't exist\n");return 0;}
 buf2=calloc(1,sizeof(char*));
 buf2=filetobuf(buf2,fp);
 cnt2=cnt;
 printf("\n cnt1=%d cnt2=%d line=%d \n",cnt1,cnt2,line);
 buf1=realloc(buf1,(cnt1+cnt2)*sizeof(char*));
 memmove(buf1+line+cnt2,buf1+line,sizeof(char*)*(cnt1-line));
 memmove(buf1+line,buf2,sizeof(char*)*(cnt2));
 for(i=0;i<cnt1+cnt2;i++)
  printf("%s",buf1[i]);
}
void* filetobuf(char** buf,FILE *fp)
{
 int i,j;
 char ch;
 for(i=0,j=0;!feof(fp);)
 {
  //printf(">>>\n ");
  buf[i]=realloc(buf[i],(j+1));
  buf[i][j++] = getc(fp);
  printf("%c",buf[i][j-1]);
  if(buf[i][j-1]=='\n')  
  {
   buf[i]=realloc(buf[i],(j+1));
   buf[i][j]=0; 
   j=0;
   i++;
   //printf("value of i=%d\n",i);
   buf=realloc(buf,sizeof(char*)*(i+1));
   buf[i]=0;
  }
 }
 fclose(fp);
 cnt=i;
 return buf;
}
