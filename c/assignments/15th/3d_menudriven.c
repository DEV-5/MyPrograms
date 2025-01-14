
//DATE:11-1-16
//DATE:15-1-16
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define si 10 

void selection();
void print(char (*str)[2][20]);
void insert(char (*str)[2][20]);
int* search(char (*s)[2][20]);
void fill_list(char(*p)[2][20]);
void str_swap(char*str1,char*str2);
void reverse(char(*p)[2][20]);
void sort(char(*p)[2][20]);
void delete(char(*p)[2][20]);
void menu();
int pm;//contains present max index

int main()
{
  while(1)
 {
  menu();
  selection();
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
       printf("        8 - TO OPEN SOURCE(3d_menudriven.c)IN VIM\n");      
       printf("        9 - TO COMPILE THE SOURCE FILE  \n");      
       printf("        0 - TO RUN 3dmenu.out\n\n");
 printf(" *************************************************\n");      
   return ;    
}

 void selection()
{
 int *a;
 static char db[10][2][20];
 char ch; 
 printf(" please enter a choice : ");
 scanf(" %c",&ch);
 system("clear");
 printf("\n you have chosen option: %c\n",ch);
 while(getchar()!=10);
 switch(ch)
 {
  case '1' : insert(db);
             return ;
             
  case '2' : print(db);
             return ;

  case '3' : a=search(db);
             return ;
 
  case '4' : sort(db);
             print(db);
             return ;

  case '5' : reverse(db);
             print(db);
             return ;

  case '6' :// delete(db,n);
             return ;
             

  case '7' : printf("\n Quiting program........\n");
             printf("\n\t\t!!! BYE !!!\n\n");
             exit(0);

  case '8' : system("clear");
             system("vim 3d_menudriven.c"); 
             system("cc 3d_menudriven.c -o 3dmenu.out");
             system("./3dmenu.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             exit(0);
           
  case '9' : printf("\n\tcompiling 3d_menudriven.c\n"); 
             system("cc 3d_menudriven.c -o 3dmenu.out");
             printf(" 3dmenu.out created\n");
             return ;

   case '0': printf("\n Executing 3dmenu.out\n"); 
             system("./3dmenu.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             exit(0);

  case 'f' : fill_list(db);
             return ;
   default: printf("\n You have entered a wrong option\n");
 }
 return ;
} 

 void print(char (*str)[2][20])
{
  int j;      
  if(pm>=1)
  {
   printf("\n The contacts are as follows: \n\n");
          printf("     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~|\n");
          printf("     |___NO____|________NAME_________|_______PHONE_NO______| \n");

   for(j=0;j<pm;j++)
          printf("     |Contact%d | %-*s| %-*s|\n",j,20,str[j][0],20,str[j][1]);
          printf("     |_________|_____________________|_____________________|\n");
  }
   else
           printf("\n The list is empty\n ");
}

 void insert(char (*str)[2][20])
{
 if(pm>=si)
 {
  printf("\n contact list is full\n");
  return ;
 }       
 printf("\n please enter a name: ");      
 fgets(str[pm][0],20,stdin);  
 str[pm][0][strlen(str[pm][0])-1]=0;
 printf("\n please enter a number:  ");      
 fgets(str[pm][1],20,stdin);  
 str[pm][1][strlen(str[pm][1])-1]=0;
 printf("\nyou have entered:\n:%s:%s:\n",str[pm][0],str[pm][1]);
 pm++;
 printf("\n the value of pm at the end =%d",pm);
 return;
}
void delete(char(*p)[2][20])
{
 int *a,in;
 printf("\n DELETER: \n");
 a=search(p);
 if(a[0]==0)
  return ;
 else
 do{
    if(in>a[0]) 
     printf("\n you have entered a wrong option");
    printf("\nplease enter the index of the contact to be deleted ");
    scanf("%d",&in);
   }while(in>a[i]);
 memmove(p+in,p[in]+,(pm-in-1)*sizeof(p[i]));
}
 int* search(char (*s)[2][20])
{
  int i=0,j,in;
  char key[20];
  char *p;
  static int *a;
  a =realloc(0,pm*sizeof(int));  
  do{
     if(i>=2)
       printf("\n You have entered a wrong option ");
     printf("\n press   0 to search by name or press 1 to search by number ]\n");
     scanf("%d",&i);
  }while(i>=2);
  printf("\n please enter the string to be searched\n");  
  scanf("%s",key);
  for(j=0,in=1;j<pm;j++)
   if(p = strstr(s[j][i],key))
    a[in++]=j; 
  a[0]=in;

  if(a[0]==0)
  {
   printf("\n Match not found \n");
   return a;       
  }
  printf("SEARCH RESULTS\n");
  for(j=1;j<a[0];j++)
    printf(" indexno%d>>>contactno%d |name: %s | phone_no: %s |\n",j,1+a[j],s[a[j]][0],s[a[j]][1]);
  return a; 
}

 void sort(char(*p)[2][20])
{
 int i,j;
 for(i=pm-1;i>=0;i--)
        for(j=0;j<i;j++)
               if(strcmp(p[j][0],p[j+1][0])>0)
               {
                str_swap(p[j][0],p[j+1][0]);
                str_swap(p[j][1],p[j+1][1]);
               }
 return;
}
void reverse(char(*p)[2][20])
{
 int i,cnt;
 for(i=0,cnt=pm-1;i<cnt;i++,cnt--)
 {
     str_swap(p[i][0],p[cnt][0]);
     str_swap(p[i][1],p[cnt][1]);
 }
 return ;
}
 void str_swap(char*str1,char*str2)
{
 char temp[20];
 strcpy(temp,str1);
 strcpy(str1,str2);
 strcpy(str2,temp);
}
 void fill_list(char (*p)[2][20])
{
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
 return ; 
}




