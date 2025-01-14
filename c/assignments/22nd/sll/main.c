//DATE: 14-12-16
#include"myheader.h"
void menu();
void print(NODE*);
void add(NODE**);
void erase(NODE**);
void delete(NODE**);
NODE* search(NODE* );

int main()
{
  char ch,c;
  NODE* head=0,*temp;
 while(1)
 {
  menu();
  for(c=0;(c=getchar())!=10&&c!=0&&c!=32;ch=c);

  switch(ch)
  {
   case 'a':
	    add(&head);
	    print(head);
            break;
   case 'p':
	    print(head);
            break;   
   case 'd':
	    delete(&head);
	    print(head);
            break;
   case 's':
	    temp = search(head);
	    if(temp==NULL)
 	       printf("\n NODE not found ");
	    else
		    printf("\n %d  is present in the sll\n",temp->data);
            break;
   case 'e':
	    erase(&head);
	    print(head);
            break;
   case 'q':
            return 0;

   default: printf("you have entered a wrong option\n");	    
  }
 }
 return 0;
}

void menu()
{
 printf("\n *************************MENU*************************\n");
 printf("PRESS: \n");
 printf(" a : to add a node to list \n");
 printf(" p : to print the entire list \n");
 printf(" d : to delete a node in list \n");
 printf(" s : to search for if the  data is present in the list \n");
 printf(" e : to entire list \n");
 printf(" q : to quit  \n");
}
