//DATE:14-12-16

#include"myhead.h"

void erase(NODE** phead)
{
 NODE* temp;
 while(*phead)
 {
  temp=(*phead);
  (*phead)=(*phead)->next;
  free(temp);
 }
}
