
#include"DEVheader.h"
void insert (char ch,NODE**phead);

 void input(NODE**phead)
{
 NODE* temp=0;
 char in;
 system("clear");
 printf(" please enter a binary number and press enter once you have done entering the number\n\t: ");
    scanf("%c",&in);
 do{
    insert(in,phead);
    scanf("%c",&in);
   }while(in!=10);
}
 void insert (char in,NODE** phead)
{
 NODE *nu;
 nu=malloc(sizeof(NODE));
// for(temp=(*phead);temp->link;temp=temp->link);
 nu->link=(*phead);
 nu->bit=in;
 (*phead)=nu;
} 
/* void insert (char in,NODE** phead)
{
 NODE*head=*phead,*temp= *phead;
 static int i=2;
 if(head==NULL)
 {
  head =(*phead) = malloc(sizeof(NODE));
 } 
 else
 {
  for(head=*phead;(head->link)!=NULL;head=head->link);
  head->link = malloc(sizeof(NODE));
  head=head->link;
 }
  head->bit=in;
  head->link=0;
  //printf("\n {%c}",head->bit);
}*/

