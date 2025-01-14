
//DATE:7-11-16
// menu driven program with  2darray 
#define si 20  //si is size of each individual strings
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu();
void print(char (*str)[20],int pm);
void delete(char (*s)[20],int n,int *i);
void sort(char (*a)[20],int n);
void search(char (*s)[20],int i);
void reverse(char (*s)[20],int i);
void insert(char (*str)[20],int n,int *i);
char selection(char (*str)[20],int n);
void str_swap(char *str,char *str2);

int main()
{
 char ch,s[10][si];        
do{     
   menu();
   ch= selection(s,10);
   }while(ch!='7');
 return 0;
}

 void menu()
{
         
 printf("\n\n **********************MENU***********************\n");      
       printf("  PRESS:   \n\n");      
       printf("        1 - TO INPUT A NAME  \n");      
       printf("        2 - TO PRINT ALL THE CONTACTS \n");      
       printf("        3 - TO SEARCH IF A CONTACT IS PRESENT \n");      
       printf("        4 - TO SORT THE CONSTACTS ALPHABATICALLY  \n");      
       printf("        5 - TO REVERSE THE ORDER OF CONTACTS \n");      
       printf("        6 - TO DELETE AN NAME AT A GIVEN INDEX \n");      
       printf("        7 - TO QUIT THE PROGRAM \n");
       printf("        8 - TO OPEN SOURCE(2d_menudriven_DMR.c)IN VIM\n");      
       printf("        9 - TO COMPILE THE SOURCE FILE  \n");      
       printf("        0 - TO RUN 2dmenu.out\n\n");
 printf(" *************************************************\n");      
   return ;    
}

 char selection(char (*str)[si],int n)
{
 char ch;
 static int pm=-1;  //contains present max index
 printf(" please enter a choice : ");
 scanf(" %c",&ch);
 system("clear");
 printf("\n you have chosen option: %c\n",ch);
 while(getchar()!=10);
 switch(ch)
 {
  case '1' : insert(str,n,&pm);
             return ch;
             
  case '2' : print(str,pm);
             return ch;

  case '3' : search(str,pm);
             return ch;
 
  case '4' : sort(str,pm);
             return ch;

  case '5' : reverse(str,pm);
             return ch;

  case '6' : delete(str,n,&pm);
             return ch;

  case '7' : printf("\n Quiting program........\n");
             printf("\n\t\t!!! BYE !!!\n\n");
             return ch;

  case '8' : system("clear");
             system("vim 2d_menudriven.c"); 
             system("cc 2d_menudriven.c -o 2dmenu.out");
             system("./2dmenu.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             exit(0);
             return '7';

  case '9' : printf("\n\tcompiling 2d_menudriven.c\n"); 
             system("cc 2d_menudriven.c -o 2dmenu.out");
             printf(" 2dmenu.out created\n");
             return ch;

   case '0': printf("\n Executing 2dmenu.out\n"); 
             system("./2dmenu.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             return '7';

   default : printf("\n you have entered a wrong option "); 
 }    
   return ch;
}   

 void print(char (*str)[si],int pm)
{
  int j;      
  if(pm>=0)
  {
   printf("\n The contacts are as follows: \n\n");
          printf("     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
          printf("     |___NO____|________NAME_________|\n");

   for(j=0;j<=pm;j++)
          printf("     |Contact%d | %-*s|\n",j+1,si,str[j]);
     //     printf("     |^^^^^^^^^^|^^^^^^^^^^^^^^^^^^^^|\n");
        printf("     |_________|_____________________|\n");
  }
   else
           printf("\n The list is empty\n ");
}

 void sort(char (*a)[si],int pm)
{
  int  i,j;

  if(pm<1)
  { 
   printf("\n sorting is not necessary ");
   return;
  }
  for(i=pm;i>0;i--)
       for(j=0;j<i;j++)
            if(strcmp(a[j],a[j+1])>0)
               str_swap(a[j],a[j+1]); 
  printf("\n the list has been sored\n");
  return;
}
  
 void reverse(char (*s)[si],int pm)
{
 int j=0;      
  for(j=0;j<pm;j++,pm--)     
          str_swap(s[pm],s[j]); 
}

 void search(char (*s)[si],int pm)
{
 char key[si];
 char *p;
 int j,in,k;
 printf("\n please enter the name that is to be searched:");
 scanf("%s",key);

 for(j=0,in=-1;j<=pm;j++)   
 { 
  if(strlen(key)>strlen(s[j]))
     j=-1;
  else if(p=strstr(s[j],key))
  {        
   printf("\n found \"%s\" at postion %d",s[j],j+1);
   in++;
  }
 }
 if(j==-1||in==-1)
   printf("\n sorry no match found \n");
 return;
}           


 void delete(char (*s)[si],int n,int *pm)
{
  int c=0,j;
  if(*pm==-1)
  {
   printf("\n Deletion is not possible as the list is empty\n");
   return;
  }

do{
   if(c>*pm)
     printf("\n there is no contact at the given postion, they are/is  only %d contacts in  the list\n",*pm+1);      
   print(s,*pm);
   printf("\nplease enter the contact index to be deleted: ");
   scanf(" %d",&c);
   c--;
   while(getchar()!=10);
  }while(c>*pm);
  
  if(c!=*pm)
   memmove(s[c],s[c+1],(*pm-c)*(sizeof(s[c])));    
       
  strcpy(s[*pm],"");
  --(*pm);   
 return;  
}

 void str_swap(char *str,char *str2)
{ 
 char temp[si];     
 strcpy(temp,str);
 strcpy(str,str2);
 strcpy(str2,temp);
 return;
}

 void insert(char (*str)[si],int n,int *pm)
{           
  if(*pm>=(n-1))
  {
   printf("\nthe array is full please delete data before inserting any more data\n");
   return;
  }    
   (*pm)++;
   printf("please enter a the name to be inserted : ");
   fgets(str[*pm],si,stdin);
   str[*pm][strlen(str[*pm])-1]=0;
   return;
} 



