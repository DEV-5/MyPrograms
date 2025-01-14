
//DATE:12-12-16
#include"myhead.h"

 void delete(NODE** phead)
{
 int input;
 NODE*temp;
 if((*phead)==NULL)
 { printf("\nDeletion is not posible as the DLL is Empty");return; }
 printf("\n please enter the data to be deleted: ");
 scanf("%d",&input); 
 while(getchar()!=10);

 if((*phead)->data==input) 
{
 if((*phead)->next) (*phead)->next->prev=NULL;
 temp=(*phead);
 (*phead)=(*phead)->next;
 free(temp);
 return;
}
 for(temp=(*phead);temp&&(temp->data!= input);temp=temp->next);
 //temp=search(*phead);
 if(temp==NULL)
 {
 printf(" node not found\n");
 return ;
 }
 else
 {
  if(temp->prev)temp->prev->next=temp->next;
  if(temp->next)temp->next->prev=temp->prev;
  free(temp); 
 }
}

