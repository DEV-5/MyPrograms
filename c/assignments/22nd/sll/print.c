#include"myheader.h"

void print(NODE* head)
{
 if(head == NULL){printf("\n THE SLL IS EMPTY\n");return ;}

 while(head)
 {
  printf("%d->",head->data);
  head=head->link;
 }
  printf("NULL\n");
}
