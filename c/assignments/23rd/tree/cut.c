
#include"head.h"

void cut(TREE** proot)
{
 if((*proot)==0) return;
 cut(&((*proot)->left));
 cut(&((*proot)->right));
 free(*proot);
}
