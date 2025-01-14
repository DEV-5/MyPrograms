
#include"DEVheader.h"
void insert (int pw,int coef,NODE** phead);

 void input(NODE**phead)
{
 NODE* temp=0;
 int pw,coef;
 char ch=0;
// system("clear");
// printf(" please enter the power of the term  and press enter once you have done entering the equation\n\t: ");
  //  scanf("%d %d",&pw,&coef);
 do{
    printf("please enter the power of the term: ");
    scanf("%d",&pw);
    printf("please enter the coefficent of the term: ");
    scanf("%d",&coef);
    insert(pw,coef,phead);
    printf("press q to quit or press another key to insert another term in the equation: "); 
    while(getchar()!=10);
    scanf("%c",&ch);
    system("clear");
   }while(ch!='q');
}
 
 void insert (int pw,int coef,NODE **phead)
{
 NODE *nu,*temp= *phead;
 static int i=2;
 nu = malloc(sizeof(NODE));
 nu->pow=pw;
 nu->co=coef;
 printf("\n nu->pow=%d nu->coef=%d\n",nu->pow,nu->co);
 if((*phead)==NULL)
 {
  printf("\n first node inserted\n");
  nu->link=0;
  (*phead)=nu;
 } 
 else if(nu->pow > (*phead)->pow)
 {
  nu->link=(*phead);
 // (*phead)->link=0;
  (*phead)=nu;

 }
 else
 {
  printf("\n entering else::::::\n");
  for(temp=*phead;temp->link&&(temp->link->pow)>pw;temp=temp->link);
  nu->link = temp->link;
  temp->link=nu;
 }
}

