//DATE:22-10-16 ;1-11-16
 int printf(const char *,...);
 int scanf(const char *,...);
 int system(const char *(clear));
 int getchar();
 //#include<stdio.h>
 void menu();
 int countnodigits(int no);
 void take_input(int* no);

 int main()
{  
  int no=0,ch,op;
   menu();
   printf("please enter a option: ");
   scanf("%d",&ch);
  while(1)
 {       
  switch(ch)
  {
   case 1: take_input(&no);
           op=countnodigits(no);
           printf("\nthe no digits present is %d",op);
           break;
   case 2: take_input(&no);    
           printf("\n");
           break;
   case 3: take_input(&no);
           printf("\n ");
           break;
   case 4: take_input(&no);
           printf("\n ");
           break;
   case 5: take_input(&no);
           printf("\n ");
           break;
   case 6: return 0;
         
   case 0: return 0;

   default:printf("\nyou have entered a wrong option now "); 
           break;
  }
   menu();
   printf("please enter a option: ");
   scanf("%d",&ch);
  // while(getchar()!=10);
 }
  return 0;
}

  void menu()
 {
         
 printf("\n\n ******************MENU*******************\n");      
       printf("  PRESS:   \n\n");      
       printf("        1 - TO COUNT THE NO OF DIGITS  \n");      
       printf("        2 - TO REVERSE DIGITS \n");      
       printf("        3 - TO SUM OF DIGITS \n");      
       printf("        4 - TO PRINT THE HIGHEST DIGIT \n");      
       printf("        5 - TO PRINT THE LOWEST  DIGIT \n");      
       printf("        6 - TO QUIT THE PROGRAM \n\n");
 printf(" *****************************************\n");      
   return ;    
 }


void take_input(int *no)
{ 
  printf("\nplease enter a number: ");
  scanf("%d",no);                       
  printf("\n no=%d\n",*no);
}

int countnodigits(int no)
{
 int i;
 for(i=0;no;no/=10,i++);

 return i;
}


