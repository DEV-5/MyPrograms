
#include"Header.h"

 STUDENT* syncdata()
{
 FILE *fp;
 int i=0;
 STUDENT *nu=0,*head;
 char ch;
 fp=fopen("datafile.txt","r");
 if(fp==NULL){printf("\n source file doesn't exist\n");return 0;}
 if(feof(fp)) {printf("\nempty file"); return 0;}
  
  nu = malloc(sizeof(STUDENT)-sizeof(void *));
  head=nu;
  while(-1)
 {
  i++;
  fread(nu,sizeof(STUDENT)-sizeof(void*),1,fp);
  if((ch=fgetc(fp))==EOF) {printf("i=%d\n",i);break;}
  fputc(ch,fp);
  nu->link = malloc(sizeof(STUDENT)-sizeof(void *));
  nu=nu->link;
 }
 nu->link=0;
 return head;
}
