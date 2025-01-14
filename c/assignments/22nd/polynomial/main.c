
//DATE:2-12-16
#include"DEVheader.h"
void insert (int pw,int coef,NODE** phead);
void input (NODE** phead);
void print(NODE*head);
void* sum(NODE* eq1,NODE* eq2);
 int main()
{
 NODE *eq1=0,*eq2=0,*ans=0;
 printf("\n now enter the equation one : \n");
 input(&eq1);
 printf("\n now enter equation two : \n");
 input(&eq2);
 printf(" the equation no one is as follows: \n");
 print(eq1);
 printf("\n the equation no two is as follows: \n");
 print(eq2);
 ans=sum(eq1,eq2);
 printf("\n the result is as follows: \n");
 print(ans);
 return 0;
}

