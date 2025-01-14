
//DATE:24-12-16
#include"head.h"

void add(TREE **,int );
void menu();
void print(TREE*);
void search(TREE*);
void cut(TREE**);
void delete(TREE**);

int main()
{
 char ch;
 int no;
 TREE *root=0;
 while(1){
          menu();
	 printf("please enter your input: ");
         while((ch=getchar())==10||ch=='\0');
         system("clear");
          switch(ch)
          {
           case 'a': printf("please enter the node in which data is to be added:");	
	             scanf("%d",&no);
		     while(getchar()!=10);
		     add(&root,no);
 	             printf("\n<|");
                     print(root);
		     printf("|>\n");
		     break;

 	   case 's': search(root);
	             break;

 	   case 'p': printf("\n<|");
		     print(root);
		     printf("|>\n");
		     break;
 	   case 'd': //delete(root);
	             break;
           
	   case 'c': cut(&root);
		     root=0;
	             break;


 	   case 'q': 
		     exit(0);

           default : printf("\n you have entered a wrong option: "); 
                     break;   
	  }
         }
 return 0;
}

 void menu()
{
 printf("\n**************MENU**************\n");
 printf(" PRESS:\n");
 printf("\t a:to add a node to the tree\n");
 printf("\t s:to search for a node in the tree\n");
 printf("\t p:to print all node in the tree(inorder)\n");
 printf("\t d:to delete a node in the tree\n");
 printf("\t c:to cop down the entire tree\n");
 printf("\t q:quit\n");
}

