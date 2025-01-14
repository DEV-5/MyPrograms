
#include"myheader.h"
void add(NODE** phead)
{
 NODE *nu,*temp;
 nu = malloc(sizeof(NODE));
 nu->link=0;

 printf("\n Please enter the data of new node to be inserted: ");
 scanf("%d",&(nu->data));
 while(getchar()!=10);

 if((*phead)==NULL)
 { 
 (*phead) = nu ;
  printf("\n adding 1st node ");
 // printf("%d =%d",nu->data,(*phead)->data);
 }
 else if(nu->data<=(*phead)->data)
 { nu->link=(*phead);
	 (*phead)=nu;
 }
  
 else
 {
  for(temp=(*phead);(temp->link)&&temp->link->data < nu->data;temp=temp->link);
  if(temp==(*phead))
  {
   nu->link=(*phead)->link;
   (*phead)->link=nu;
  }
  else
  {
  if(temp->link) nu->link=temp->link;
   temp->link=nu;
  }
 }
}

