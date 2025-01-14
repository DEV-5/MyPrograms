//date: 12-12-16
#include"myhead.h"

void erase(NODE** phead);
void print(NODE*);
void delete(NODE**);
void add(NODE**);

void menu();

 int main()
{
 char ch,c;
 NODE *head=0;
 while(1)
 {
  menu();
 // scanf("%c",&ch);
 // printf("\n ENTER:\n");
  for(c=0;(c=getchar())!=10&&c!='\0'&&c!=' ';ch=c);
 // while(getchar()!=10);
 // printf("you entered %c\n",ch);
  switch(ch)
  {
  printf("\n inside switch-case: %c",ch);
   case 'a':
	    add(&head);
	    break;
   case 'd':
	    delete(&head);
	    break;
   case 'p':
	    print(head);
	    break;
   case 's':
	   //search(head);
	    break;
   case 'e':
	   erase(&head);
	    break;
   case 'q':
	    return 0;

   default: printf("\n you have entred the wrong option");
   }

 }
}
void menu()
{
 printf("\n************MENU*************\n");
 printf(" PRESS: \n");
 printf(" a : to add a node in increasing order\n");
 printf(" d : to delete a node containing supplied data \n");
 printf(" p : to print the entire link list\n");
 printf(" s : to search if supplied data is present in any node of the dll\n");
 printf(" e : to erase the dll completely \n");
 printf(" q : to quit the program \n");
}
