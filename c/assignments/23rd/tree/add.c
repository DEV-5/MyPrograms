
#include"head.h"

 void add(TREE** pnode ,int n)
{
 if((*pnode)==NULL)
 {
  (*pnode) = calloc(1,sizeof(TREE));
  (*pnode)->data=n;  
  return ;
 }
 else
 {
   if((*pnode)->data>=n)
  {
   add(&((*pnode)->left),n);
  }
  else
  {
   add(&((*pnode)->right),n);
  }
 }
}
