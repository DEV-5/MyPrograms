
//DATE:14-11-16
// menu driven program with  2darray using dynamic memory allocation and pointers.
#define si 20  //si is size of each individual strings
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int pm=0;
int n=10;

void menu();
void print(char **str);
void * insert(char **str);
void* delete(char **p);
void sort(char **a);
void* search(char **s,char *key);
void reverse(char **s);
char selection();
void str_swap(char **str,char **str2);
void* fill_list(char**);
void* deleter(char **p,int c);

 int main()
{
 char ch;
 while(ch!='7'){     
                menu();
                ch=selection();
                }
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
       printf("        8 - TO OPEN SOURCE(2d_dma_ptr.c)IN VIM\n");      
       printf("        9 - TO COMPILE THE SOURCE FILE  \n");      
       printf("        0 - TO RUN 2ddmaptr.out\n\n");
 printf(" *************************************************\n");      
 return ;    
}

 char selection()
{
 int i,*a;
 char ch;
 static char **str=0,key[20];
 printf(" please enter a choice : ");
 scanf(" %c",&ch);
 system("clear");
 printf("\n you have chosen option: %c\n",ch);
 while(getchar()!=10);
 switch(ch)
 {
  case 'c' : str=realloc(str,0);
             printf(" THE LIST HAS BEEN CLEARED\n");
             pm=0;
             return ch; 

  case 'f' : str=fill_list(str);
             return ch; 


  case '1' : str = insert(str);
             print(str);
             return ch;
             
  case '2' : print(str);
             return ch;

  case '3' : if(pm==0){printf("\n the list is empty ");return ch;}
             printf("\n please enter the name that is to be searched:");
             scanf("%s",key); 
             a=search(str,key);
             if(a[0]==-0)
             {
              printf("\n  No Match Found \n");
             }       
             for(i=1;i<=a[0];i++)
             printf("\n found \"%s\" at postion %d",str[a[i]],a[i]);
             return ch;
 
  case '4' :
             sort(str);
             print(str);
             return ch;

  case '5' : reverse(str);
             print(str);
             return ch;

  case '6' : str=delete(str);
             return ch;

  case '7' : printf("\n Quiting program........\n");
             printf("\n\t\t!!! BYE !!!\n\n");
             exit(0);
             return ch;

  case '8' : system("clear");
             system("vim 2d_dma_ptr.c");
             system("cc 2d_dma_ptr.c");
             system("cc 2d_dma_ptr.c -o 2ddmaptr.out");
             system("./2ddmaptr.out");
             exit(0);
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             return ch;

  case '9' : printf("\n\tcompiling 2d_dma_ptr.c\n"); 
             system("cc 2d_dma_ptr.c -o 2ddmaptr.out");
             printf(" 2ddmaptr.out created\n");
             return ch;

   case '0': printf("\n Executing 2ddmaptr.out\n"); 
             system("./2ddmaptr.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             return ch;

   default : printf("\n you have entered a wrong option "); 
 }    
   return ch;
}   

 void* fill_list(char **p)
{
 int i;
 p=realloc(p,0);
 p=realloc(p,10*sizeof(char *));
 for(i=0;i<10;i++)
 p[i]=realloc(0,7);
 strcpy(p[0],"one");
 strcpy(p[1],"two");
 strcpy(p[2],"three");
 strcpy(p[3],"four");
 strcpy(p[4],"five");
 strcpy(p[5],"six");
 strcpy(p[6],"seven");
 strcpy(p[7],"eight");
 strcpy(p[8],"nine");
 strcpy(p[9],"ten");
 pm=10;
 print(p);
 return p; 
}

 void print(char **str)
{
  int j;      
  if(pm>0)
  {
   printf("\n The contacts are as follows: \n\n");
   printf("     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
   printf("     |___NO_____|________NAME_________|\n");
   
   for(j=0;j<pm;j++)
    printf("     |Contact %-2d| %-*s|\n",j+1,si,str[j]);
   printf("     |__________|_____________________|\n");
  }
  else
    printf("\n The list is empty\n ");
}

 void* insert(char **str)
{     
 int i=0;
 str = realloc(str,(pm+1)*sizeof(str));
 str[pm]=0;

 printf("\nplease enter a the name to be inserted : ");
 do{
    str[pm]=realloc(str[pm],1+i);
    str[pm][i]=getchar();
   }while(str[pm][i++]!='\n');
 str[pm][i-1]=0;
 printf("\n %lu ",strlen(str[pm]));
 pm++;
 return str;
} 

 void sort(char **a)
{
  int  i,j;
  char *temp;
  if(pm<2)
  { 
   printf("\n sorting is not necessary ");
   return;
  }
  for(i=pm-1;i>0;i--)
    for(j=0;j<i;j++)
      if(strcmp(a[j],a[j+1])>0)
      {
       str_swap(a+j,a+j+1);
      } 
  printf("\n the list has been sored\n");
  return;
}
 
 void reverse(char **s)
{       
 int j=0,cnt=pm;      
 for(j=0;j<(cnt-1);j++,cnt--)     
 str_swap(s+j,s+cnt-1);
}

 void* search(char **s,char *key)
{
 static int *a=0;
 char *p;
 int j,in,k;
 a=realloc(a,0);
 a = realloc(a,sizeof(int)*(pm+1));
 for(j=0,in=0;j<pm;j++)   
 { 
  if(strlen(key)>strlen(s[j]))
   continue;
  else if(p=strstr(s[j],key))
  { 
   in++;
   a[in]=j;        
  }
  a[0]=in;
 }
 return a;
}          

 void* delete(char **s)
{
  int c=0,i,*a;
  char key[si]="";
  if(pm==0)
  {
   printf("\n Deletion is not possible as the list is empty\n");
   return s;
  }
  printf("\nplease enter the contact or part of it to be deleted: ");
  scanf("%s",key);
  a=search(s,key);
  if(a==NULL)
    return s;
  printf("\n SEARCH RESULTS: \n");        
  for(i=1;i<=a[0];i++)
   printf("\n\t%d:%s ",i,s[a[i]]);
  do{
     if(i==0)
      return s; 
     printf("\nplease enter the index of the search result to delete it or press 0 tor goto menu: "); 
     scanf("%d",&i);
    }while(i>a[0]);
  s=deleter(s,a[i]);
  return s;  
}

 void* deleter(char **s,int c)
{
 memmove(s+c,s+c+1,(pm-c-1)*sizeof(char *));
 --pm;   
 s = realloc(s,(pm)*si);
 return s;
}

 void str_swap(char **str,char **str2)
{ 
 char *temp;   
       temp = *str;        
       *str = *str2;
       *str2 = temp;          
 return;
}

