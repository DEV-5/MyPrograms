
#include"DEVheader.h"

int btoi(NODE* head)
{
 int i,res;
 for(i=1,res=0;head;i*=2)
 {   
         //printf("\n i=%d and res=%d head->bit=%c",i,res);
     res+=((head->bit-48)*i);
     head=head->link;
 }
 return res;
}
