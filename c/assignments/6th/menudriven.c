
//DATE:22-10-16 ;1-11-16
//Purpose: write a menu driven program to find the number a digits present or find the reverse of a  number or the sum of the digits or 
//         highest or the lowest value amongst the inputs.  
#define s 20
#include<stdlib.h>
#include<unistd.h>
 int printf(const char *,...);
 int scanf(const char *,...);
 int system(const char *(clear));
 int getchar();

 void menu();
 void countnodigits(int* no);
 void take_input(int* no);
 int choice();
 void insert(int stu[]);
 void print(int stu[]);
 void highest(int *p);
 void lowest(int *p);
 int sumofdigits(int no);
 void reversedigits();
 
 int main()
{  
  int no=0,ch,op,n[s];
  srand(getpid());
  ch=choice();
  while(1)
 {       
   switch(ch)
  {
   case 1: take_input(&no);
           countnodigits(&no);
           printf("\nthe number of digits present is %d ",no);
           break;
   case 2: 
           take_input(&no);
           reversedigits(&no);     
           printf("\nthe reversed digit is %d ",no);
           break;
   case 3: 
           take_input(&no);
           printf("\nthe sum of digits of %d is %d",no,sumofdigits(no));
           break;
   case 4: 
           highest(n);
           printf("\n ");
           break;
   case 5: 
           lowest(n);
           printf("\n ");
           break;
   case 6: return 0;
   
   default:printf("\nyou have entered a wrong option now "); 
  }
    ch=choice();
 }
  return 0;
}

 int sumofdigits(int no)
{
  int i,sum;
 for(i=0,sum=0;i<s;i++,no/=10) 
  sum+=no%10; 
 return sum;
}
  void highest(int *p)
 {
   int i,big;
   insert(p);
   print(p);   
   for(i=1,big=0;i<s;i++)
   {
    if(p[i]>p[big])
      big=i; 
   }
   printf("the highest value in the list is %d",p[big]);
 }

  void lowest(int *p)
 {
   int i,low;
   insert(p);
   print(p);   
   for(i=1,low=0;i<s;i++)
   {
    if(p[i]<p[low])
    low=i; 
   }
   printf("the lowest value in the list is %d",p[low]);
 }

 void reversedigits(int *no)
{
 int rev,i;
  for(i=0,rev=0;*no;i++) 
  {
   rev=rev*10+*(no)%10;
   *no/=10;
  }
  *no=rev;
  return ;
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
  return;
}

 void countnodigits(int *no)
{
 int i;
 for(i=0;*no;*no/=10,i++);
 *no=i;
}

 int choice()
{
   int ch;
   menu();
   printf("please enter a option: ");
   scanf("%d",&ch);
   while(getchar()!=10);
   return ch;
} 

 void print(int stu[])
{
 int i;       
  printf("\n\t");
  for(i=0;i<s;i++)
    printf("%*d,",3,stu[i]);  
  printf("\n\t");
  for(i=0;i<s;i++)
    printf("%*d,",3,i); 
  printf("\n");
}

 void insert(int stu[])
{      
  int i;      
  for(i=0;i<s;i++)
    stu[i]=rand()%101;
}


