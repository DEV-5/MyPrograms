
//DATE:30-11-16
 #include"Header.h"
 void save(STUDENT* head)
{
 FILE *fp;
 if(head==NULL)return;
 fp=fopen("datafile.txt","w");
 while(head)
 {
  fwrite(head,sizeof(STUDENT)-sizeof(void*),1,fp);
  head=head->link;
 }
 fclose(fp);
 return ; 
}
