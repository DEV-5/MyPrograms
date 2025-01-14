
//DATE:2-12-16
#include"DEVheader.h"
void insert (char in,NODE** phead);
void input (NODE** phead);
void print(NODE*head,int ans);
int btoi(NODE*head);
 int main()
{
 int ans;
 NODE*head=0;
 input(&head);
 ans=btoi(head);
 print(head,ans);
 return 0;
}

