
#include"head.h"
void search(TREE* node)
{
 int no;
 printf("please enter the data to be searched\n"); 
 scanf("%d",&no);
 while(getchar()!=10);
 while(node)
 {
  if(node->data==no){printf("the data is present in the TREE \n");return ;}
  else if(node->data>no) node=node->left;
  else node=node->right;
 }
 printf("\n the data is not present in the TREE\n");
}

