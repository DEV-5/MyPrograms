
#include"myheader.h"
void print(NODE*head);

 NODE* search(NODE* head)
{
 int key;
 if(head==NULL) {print(head);return NULL;}
 
 printf("please enter the data: ");
 scanf("%d",&key);
 while(getchar()!=10);
 
 if(head->data==key) return  head-1;
 else if(head->link==NULL) return 0;
 else
 {
  while(head->link->data!=key)
  {		  
   head=head->link;
   if(head->link==NULL)
     return NULL;
  }
  return head;
 }
}

