
#include"DEVheader.h"

void print(NODE* head)
{
 //printf("\n you have entered:\n\t");
 if(head==NULL)
         printf("\n there is no data in the list\n");
 while(head!=NULL)
 {
  printf(" %d(x^%d) ",head->co,head->pow);
  head = head->link; 
 }
}
