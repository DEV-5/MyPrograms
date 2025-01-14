//date:12-12-16		
#include"myhead.h"

void add(NODE** phead)
{
 NODE* nu,*temp,*pre;
 nu=calloc(1,sizeof(NODE));
 printf("please enter the data: ");
 scanf("%d",&(nu->data));
 while(getchar()!=10);
 if((*phead)==NULL)
 {	
  *phead=nu;
  return;
 }
 else if(((*phead)->data) > nu->data)
 {
  (*phead)->prev=nu;
  nu->next = (*phead);
  (*phead)=nu;
 }
 else
 {
  for(temp=*phead;temp&&(nu->data>temp->data);pre=temp,temp=temp->next);
  if(temp==NULL)
  {
   pre->next=nu;
   nu->prev=pre;
   return ;
  }
  if(temp->prev) temp->prev->next=nu;
  nu->next=temp;
  nu->prev=temp->prev;
  temp->prev=nu;
  if(nu->prev) nu->prev->next=nu;
 }
}
