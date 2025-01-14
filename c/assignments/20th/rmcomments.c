
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max;
void* deletecoments(char**buf);

int main(int argc,char**argv)
{ 
 FILE *fp;
 char** buf=0,*fname;
 int i,j;
 if(argc!=2){printf("\n incorrect number of arguments\n");return 0;} 
 fp=fopen(argv[1],"r");
 if(fp==NULL){printf("\n Source file is empty\n");return 0;} 
 buf=realloc(0,sizeof(char*));
 printf("%u\n",buf[0]); 
 for(i=0,j=0;!feof(fp); )
 {
 // if(i==5) printf("\ni=%d\n",i);
 // if(i>2) printf("buf[%d]=realloc(buf[%d],%d+1)\n",i,i,j);
  buf[i] = realloc(buf[i],j+1); 
 // if(i==5){printf("end %d:%lu\n",i,buf[i]+j);}
  buf[i][j++]=fgetc(fp); 
 // printf("<%c>%lu|i=%d\n",buf[i][j-1],buf[i]+j,i); 
  if(buf[i][j-1]=='\n')
  {
   buf[i] = realloc(buf[i],j+1); 
   buf[i][j]=0;
   j=0;
  // printf("line %d:%lu\n",i,buf+i);
   i++;
 //if(i==5)buf[i] = realloc(buf[i],j+1); 
   buf=realloc(buf,(i+1)*sizeof(char*));
   buf[i]=0;
   //if(i==5){printf("line %d:%lu\n",i,buf+i);}
  }
 }
 printf("\n checkpoint1->");
 max=i;
 buf[i][j-1]=0;
 fclose(fp);
 printf("\n before deletion\n");
 for(i=0;i<max;i++)
  printf("%s",buf[i]); 
 printf("\n checkpoint2->");
 buf=deletecoments(buf);
 /*
 fname = malloc(strlen(argv[1])+1);
 strncpy(fname,argv[1],strlen(argv[1])-2);
 strcat(fname,".i");
 fp=fopen(fname,"w");
 fputs(buf,fp);
 fclose(fp);*/
 printf("\n After deletion:\n");
 for(i=0;i<max;i++)
 printf("%s",buf[i]); 
 return 0;
}

 void* deletecoments(char**buf)
{
 char*p,*q;
 int dif,i;
 for(i=0,p=buf[0];i<=max;i++,p=buf[i])
 { 
  printf("loop no(%s):%d\n",(strstr(buf[i],"//")),i);
  if((p=strstr(buf[i],"//")))
 {
  //printf("step1\n");
  for(q=p ;(*p)!='\n';p++);
  memmove(q,p,strlen(q)+1);
  if(*(buf[i])=='\n')
  {\
  printf("\n deletion comencing");
  free(buf[i]); 
  printf(" ...........\n");
  memmove(buf+i,buf+i+1,(max-i-1)*sizeof(char*));
  buf = realloc(buf,(--max)*sizeof(char*));
  }
 } 
  else
 {
   p=buf[i];
   if(p=strstr(buf[i],"/*"))
  {
   for(q=p ;*p!='*'||*(p+1)!='/';p++);
   memmove(q,p,strlen(p)+1);
   buf=realloc(buf,strlen(buf[i])+1-strlen(q)+strlen(p));
  }
 }
}
//printf("\n contact has been made");
 return buf; 
}
 
