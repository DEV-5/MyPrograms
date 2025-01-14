//DATE:12-12-16

#include"myhead.h"

 void print(NODE* head)
{
 if(head==NULL)
 { printf("\n The DLL is Empty");return ;}
 while(head)
 {
 printf("%d->",head->data);
 head=head->next;
 }
 printf("NULL");
}
