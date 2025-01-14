
#include"Header.h"
void add(STUDENT** );
void print(STUDENT* );
void del(STUDENT** );
void menu();
void selection(STUDENT** head);
void save(STUDENT* head);
STUDENT* syncdata();
 
 int main()
{
 STUDENT *head;
 head=syncdata();
  while(1)
 {
  menu();
  selection(&head);
 }
}
 
 void menu()
{
         
 printf("\n\n **********************MENU***********************\n");      
       printf("  PRESS:   \n\n");      
       printf("        a - TO INPUT A NAME  \n");      
       printf("        p - TO PRINT ALL THE CONTACTS \n");      
       printf("        s - TO SEARCH IF A CONTACT IS PRESENT \n");      
       printf("        c - TO CLEAR THE CONTANTS OF FILE \n");      
    //   printf("        4 - TO SORT THE CONSTACTS ALPHABATICALLY  \n");      
    //   printf("        5 - TO REVERSE THE ORDER OF CONTACTS \n");      
       printf("        d - TO DELETE AN NAME AT A GIVEN INDEX \n");      
       printf("        q - TO QUIT THE PROGRAM \n");
     //  printf("        f - TO AUTO FILL 4 ENTRIES \n");
       printf("        s - TO SAVE PRESENT ENTRIES TO A FILE \n");
    /*   printf("        8 - TO OPEN SOURCE(f_stu_aos.c)IN VIM\n");      
       printf("        9 - TO COMPILE THE SOURCE FILE  \n");      
       printf("        0 - TO RUN fstuaos.out\n\n");*/
 printf(" *************************************************\n");      
   return ;    
}

 void selection(STUDENT **head)
{
 int *a;
 char ch; 
 FILE *fp;
 printf(" please enter a choice : ");
 scanf(" %c",&ch);
 system("clear");
 printf("\n you have chosen option: %c\n",ch);
 while(getchar()!=10);
 switch(ch)
 {
  case 'a' : add(head);
             return ;
             
  case 'p' : print(*head);
             return ;

  case 's' : save(*head);
             return ;
 
  case 'd' :  del(head);
              return;
  
  case 'q' :  exit(0);

  case 'c' :  fp=fopen("datafile.txt","w");
              fclose(fp);
              return;
/*case '4' : sort(db);
             print(db);
             return ;

  case '5' : reverse(db);
             print(db);
             return;
*/
  default: printf("\n Incorrect option\n");
 }
}
