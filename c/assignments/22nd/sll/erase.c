
#include"myheader.h"

 void erase (NODE** phead)
{
 NODE *temp;
 while((*phead))
 {
  temp=(*phead);
  (*phead)=(*phead)->link;
  free(temp);
 }
}
