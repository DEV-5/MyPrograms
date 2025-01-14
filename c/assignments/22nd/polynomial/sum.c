
//DATE: 3-12-16
#include"DEVheader.h"

 void* sum(NODE* eq1,NODE* eq2)
{
 NODE *res,*q1,*q2,*tres,*temp;
 if((eq1==NULL)||(eq2==NULL))
 {
  printf("\n list is empty\n");
         return NULL;
 }
 tres=calloc(1,sizeof(NODE));    
 res = tres;
 for(q1=eq1,q2=eq2;1;tres=tres->link)
 {
  if((q1->pow)>(q2->pow))
  { 
   tres->pow= q1->pow;  
   tres->co= q1->co;  
   q1=q1->link;
  }
  else if((q2->pow)>(q1->pow))
  { 
   tres->pow= q2->pow;  
   tres->co= q2->co;  
   q2=q2->link;
  }
  else
  {
   tres->pow= q2->pow;  
   tres->co= (q2->co)+(q1->co);  
   q1=q1->link;
   q2=q2->link;
  }  
  if(!(q1)||!(q2))
  {
   printf("\n end of list\n");
   return res;
  }
  tres->link=malloc(sizeof(NODE));    
 }
 return res;
}

