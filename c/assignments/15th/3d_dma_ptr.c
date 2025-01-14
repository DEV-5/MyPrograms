
//DATE:14-11-16
// menu driven program with  3darray using dynamic memory allocation
#define si 2  //si is the of 1d arrays
char cont[][20]={"name","phone_no","email id","alternate contact no","alternate email id"};       

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int pm;
int strlen_max;

void menu();
void print(char ***str);
void * insert(char ***str);
char selection();
void* delete(char ***p);
void sort(char ***a);
void* search(char ***s);
void reverse(char ***s);
void str_swap(char **str,char **str2);
void* fill_list(char***);
void* deleter(char ***p,int c);

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
       printf("        8 - TO OPEN SOURCE(3d_dma_ptr.c)IN VIM\n");      
       printf("        9 - TO COMPILE THE SOURCE FILE  \n");      
       printf("        f - TO AUTO FILL CONTACTS  \n");      
       printf("        c - TO CLEAR ALL CONTACTS  \n");      
       printf("        0 - TO RUN 3ddmaptr.out\n\n");
 printf(" *************************************************\n");      
 return ;    
}

 char selection()
{
 int i,j,*a;
 char ch;
 static char ***str=0;
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

  case '3' : a=search(str);
             return ch;
 
  case '4' : sort(str);
             print(str);
             return ch;

  case '5' : reverse(str);
             print(str);
             return ch;

  case '6' : str=delete(str);
             print(str);
             return ch;

  case '7' : printf("\n Quiting program........\n");
             printf("\n\t\t!!! BYE !!!\n\n");
             exit(0);
             return ch;

  case '8' : system("clear");
             system("vim 3d_dma_ptr.c");
             system("cc 3d_dma_ptr.c");
             system("cc 3d_dma_ptr.c -o 3ddmaptr.out");
             system("./3ddmaptr.out");
             exit(0);
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             return ch;

  case '9' : printf("\n\tcompiling 3d_dma_ptr.c\n"); 
             system("cc 3d_dma_ptr.c -o 3ddmaptr.out");
             printf(" 3ddmaptr.out created\n");
             return ch;

   case '0': printf("\n Executing 3ddmaptr.out\n"); 
             system("./3ddmaptr.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             return ch;

   default : printf("\n you have entered a wrong option "); 
 }    
   return ch;
}   

 void print(char ***str)
{
  int j;      
  if(pm>0)
  {
   printf("\n The contacts are as follows: \n\n");
   printf("     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
   printf("     |___NO_____|________NAME_________|______PHONE_NO_______|\n");

   for(j=0;j<pm;j++)
    printf("     |Contact %-2d| %-*s| %-*s|\n",j+1,20,str[j][0],20,str[j][1]);
   printf("     |__________|_____________________|_____________________|\n");
  }
   else
       printf("\n The list is empty\n ");
}

 void* insert(char ***str)
{     
 int i=0,j=0;
 str = realloc(str,(pm+1)*sizeof(char *));
 str[pm] = realloc(str[pm],si*sizeof(char *));
 //str[pm][0]=0;
 //str[pm][1]=0;
for(j=0;j<si;j++)
{
 printf("\nplease enter a the %s to be inserted : ",cont[j]);
 do{
    str[pm][j]=realloc(str[pm][j],1+i);
    str[pm][j][i]=getchar();
   }while(str[pm][j][i++]!='\n');
 str[pm][j][i-1]=0;
 if(strlen(str[pm][j])>strlen_max)
     strlen_max=strlen(str[pm][j]);
 i=0;
 }
 pm++;
 return str;
} 

 void sort(char ***a)
{
  int  i,j,k;
  char *temp;
  if(pm<2)
  { 
   printf("\n sorting is not necessary ");
   return;
  }
  for(i=pm-1;i>0;i--)
    for(j=0;j<i;j++)
      if(strcmp(a[j][0],a[j+1][0])>0)
       for(k=0;k<si;k++)
        str_swap(a[j]+k,a[j+k]+k);
      
  printf("\n the list has been sored\n");
  return;
}
 
 void reverse(char ***s)
{       
 int j,k,cnt=pm;      
  for(j=0;j<(cnt-1);j++,cnt--)     
  for(k=0;k<si;k++)
   str_swap(s[j]+k,s[cnt-1]+k);
}

 void* search(char ***s)
{
 char*key=0;       
 static int *a=0;
 char *p;
 int j,in,k=0;
 key=realloc(0,strlen_max); 
 a=realloc(a,0);
 a = realloc(a,sizeof(int)*(pm+1)); 
 if(pm==0){printf("\n the list is empty ");return a;}
 do{  
    if(k>=si)
      printf("\nYOU ENTERED A WRONG OPTION\n");       
    for(k=0;k<si;k++)
     printf("press %d to search by %s\n",k,cont[k]);
    scanf("%d",&k);
   }while(k>=si);
  printf("\n please enter the %s that is to be searched:",cont[k]);
  scanf("%s",key); 
     
 for(j=0,in=0;j<pm;j++)   
 { 
  if(strlen(key)>strlen(s[j][k]))
   continue;
  else if(p=strstr(s[j][k],key))
  { 
   in++;
   a[in]=j;        
  }
  a[0]=in;
 } 
 if(a[0]==-0)
 {
  printf("\n  No Match Found \n");
  return a; 
 }
  printf("\n \tSEARCH RESULTS: \n");
 for(j=1;j<=a[0];j++)
 { 
  printf("\n index no %d Contact no %d ",j,a[j]+1);
  for(k=0;k<si;k++)
 printf("  %s : \"%s\" ",cont[k],s[a[j]][k]);
 }
 return a;
 }          

 void* delete(char ***s)
{
  int c=0,i,*a;
  char key[si]="";
  if(pm==0)
  {
   printf("\n Deletion is not possible as the list is empty\n");
   return s;
  }
  printf("\nDELETER \n");
   a=search(s);
  if(a[0]==0)
    return s;
  do{
     if(i==0)
      return s; 
     printf("\nplease enter the index of the search result to delete it or press 0 tor goto menu: "); 
     scanf("%d",&i);
     printf("\n\t%d ",a[0]);
    }while(i>a[0]);
  s=deleter(s,a[i]);
  return s;  
}

 void* deleter(char ***s,int c)
{
 memmove(s+c,s+c+1,(pm-c-1)*sizeof(char *));
 --pm;   
 s = realloc(s,pm*(sizeof(char *)));
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
 void* fill_list(char ***p)
{
 int i,j;
 p=realloc(p,0);
 p=realloc(p,10*sizeof(char *));
 
 for(j=0;j<10;j++)
 {
  p[j]=realloc(0,2);
  for(i=0;i<2;i++)
    p[j][i]=realloc(0,7);
 }
 strcpy(p[0][0],"one");
 strcpy(p[0][1],"1");
 strcpy(p[1][0],"two");
 strcpy(p[1][1],"2");
 strcpy(p[2][0],"three");
 strcpy(p[2][1],"3");
 strcpy(p[3][0],"four");
 strcpy(p[3][1],"4");
 strcpy(p[4][0],"five");
 strcpy(p[4][1],"5");
 strcpy(p[5][0],"six");
 strcpy(p[5][1],"6");
 strcpy(p[6][0],"seven");
 strcpy(p[6][1],"7");
 strcpy(p[7][0],"eight");
 strcpy(p[7][1],"8");
 strcpy(p[8][0],"nine");
 strcpy(p[8][1],"9");
 strcpy(p[9][0],"ten");
 strcpy(p[9][1],"10");
 pm=10;
 print(p);
 return p; 
}


