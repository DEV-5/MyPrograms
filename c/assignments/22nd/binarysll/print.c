
#include"DEVheader.h"

void print(NODE* head,int ans)
{
 printf("\n you have entered:\n\t");
 if(head==NULL)
         printf("\n there is no data in the list\n");
 while(head!=NULL)
 {
  printf("%c",head->bit);
  head = head->link; 
 }
 printf("\n It's integer equivalent is %d\n",ans); 
}
