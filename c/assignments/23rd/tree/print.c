
#include"head.h"

 void print (TREE* node)
{
 if(node==0){printf(" the tree is empty ");return ;}
  if(node->left)print(node->left);
  printf("-%d-",node->data);
  if(node->right)print(node->right);
 // if(node->left)print(node->left);
}
