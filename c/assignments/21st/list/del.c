
#include"Header.h"

 void del(STUDENT **phead)
{
 STUDENT *temp,*pre;
 int roll2del;
 if(*phead==NULL){printf("\n deltion si not possible as list is empty ");return ;}
 printf("\n Enter the poll of the student to be deleted : ");
 scanf("%d",&roll2del);
 temp=*phead;
 while(temp&&((temp->roll)!=roll2del))
 {
  pre=temp;
  temp=temp->link;
 }
 if(temp==NULL){printf("\n roll not present in the list\n");return ;}
 if(temp==*phead)
  *phead=temp->link;
 else
  pre->link=temp->link; 
 free(temp);
 return;
}
