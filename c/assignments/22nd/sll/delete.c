
#include"myheader.h"

NODE* search(NODE* head);

void delete(NODE**phead)
{
 NODE* node2del,*temp=(*phead);
 temp--;
 node2del = search(*phead);
 if(node2del==NULL){printf("\n Deletion not possible as sll is empty\n");return;}
 else if(node2del == temp)
 { 
  ++node2del;
  (*phead)=(*phead)->link;
  free(node2del);
  return;
 }
 else
 {
  temp=node2del->link;
  if(node2del->link)node2del->link = node2del->link->link;
  free(temp);
 }
}
