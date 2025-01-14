
//DATE:23-1-16
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define si 10 
int pm;//contains present max index

struct stu{
           struct {
                   int  day;
                   int  month;
                   int  year;
                  }dob;
           struct {
                   float tenth;
                   float twelfth;
                   float grad;
                  }marks;
           struct{
                  int year;
                  char series[4];
                 }id;
           char * name;
           char *phno;
           char *email;
         };

void menu();
void selection();
void print(struct stu*);
void* insert(struct stu*);
void * dynamic_input();
void* filler(struct stu* stud,char *name,char *email,char *phno,int id_year,char *series,int day,int month,int year,float tenth,float twelfth,float grad);
void* fill_list(struct stu*);
void save_list(struct stu*);
int* search(struct stu* st);
void* delete(struct stu*p);
void str_swap(struct stu *a,int x,int y);
void sort(struct stu*);
void reverse(struct stu*);
char* itoa(int n);
void load_list();

static struct stu *db=0;

int main()
{
    load_list();//load existing list
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
       printf("        f - TO AUTO FILL 4 ENTRIES \n");
       printf("        s - TO SAVE PRESENT ENTRIES TO A FILE \n");
       printf("        8 - TO OPEN SOURCE(f_stu_aos.c)IN VIM\n");      
       printf("        9 - TO COMPILE THE SOURCE FILE  \n");      
       printf("        0 - TO RUN fstuaos.out\n\n");
 printf(" *************************************************\n");      
   return ;    
}

 void selection()
{
 int *a;
 char ch; 
 printf(" please enter a choice : ");
 scanf(" %c",&ch);
 system("clear");
 printf("\n you have chosen option: %c\n",ch);
 while(getchar()!=10);
 switch(ch)
 {
  case '1' : db=insert(db);
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

  case '6' : db=delete(db);
             return ;
             

  case '7' : printf("\n Quiting program........\n");
             printf("\n\t\t!!! BYE !!!\n\n");
             exit(0);

  case '8' : system("clear");
             system("vim f_stu_aos.c"); 
             system("cc f_stu_aos.c -o fstuaos.out");
             system("./fstuaos.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             exit(0);
           
  case '9' : printf("\n\tcompiling f_stu_aos.c\n"); 
             system("cc f_stu_aos.c -o fstuaos.out");
             printf(" fstuaos.out created\n");
             return ;

   case '0': printf("\n Executing stuaos.out\n"); 
             system("./fstuaos.out");
             printf("\n\n GOING BACK TO THE OLD PROGRAM\n");
             exit(0);

  case 'f' : db=fill_list(db);
             return; 
  case 's' : save_list(db);
             system("cat studentdatabase");
             return;
           

   default: printf("\n You have entered a wrong option\n");
 }
 return ;
} 
 void save_list(struct stu* st)
{
    FILE *fp;
    char ch;
    int i=0;
    fp=fopen("studentdatabase","w");
    if(fp!=NULL)printf("\n OVERWRITING FILE \n");
    fputc('\n',fp);
    for(i=0;i<pm;i++)
    {
        fputs(itoa(strlen((st+i)->name)),fp);
        fputs((st+i)->name,fp);
        fputc('|',fp);
        fputs(itoa(strlen((st+i)->email)),fp);
        fputc('|',fp);
        fputs((st+i)->email,fp);
        fputc('|',fp);
        fputs(itoa(strlen((st+i)->phno)),fp);
        fputc('|',fp);
        fputs((st+i)->phno,fp);
        fputc('|',fp);
        fputs(itoa(strlen((st+i)->id.series)),fp);
        fputc('|',fp);
        fputs((st+i)->id.series,fp);
        fputc('|',fp);
        fputs(itoa((st+i)->id.year),fp);
        fputc('|',fp);
        fputs(itoa((st+i)->marks.tenth),fp);
        fputc('|',fp);
        fputs(itoa((st+i)->marks.twelfth),fp);
        fputc('|',fp);
        fputs(itoa((st+i)->marks.grad),fp);
        fputc('\n',fp);
 }
    //fputs("yolo",fp);
    fclose(fp);
    return;
}

void load_list()
{
    FILE fp;
    fp=fopen("studentdatabase","r");
}

void print(struct stu *st)
{
 int j;      
 if(pm>=1)
 {
  printf("\n The contacts are as follows: \n\n");
         // printf("     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~|\n");           
         // printf("     |___NO____|________NAME_________|_______PHONE_NO______| \n");
        //  printf("     |Contact%d | %-*s| %-*s|\n",j,20,str[j][0],20,str[j][1]);
        //  printf("     |_________|_____________________|_____________________|\n");
  for(j=0;j<pm;j++)
  {
   printf("\n%d.|student name:%s | email_id:%s |phone_no: %s | D.O.B %d-%d-%d |",j+1,(st+j)->name,(st+j)->email,(st+j)->phno,(st+j)->dob.day,(st+j)->dob.month,(st+j)->dob.year);
    printf(" percentages (10th:%.2f 12th:%.2f graduation:%.2f ) student_id: %d%s\n",(st+j)->marks.tenth,(st+j)->marks.twelfth,(st+j)->marks.grad,(st+j)->id.year,(st+j)->id.series);
  }
 }
   else
           printf("\n The list is empty\n ");
}

 void* insert(struct stu *student)
{
  student=realloc(student,(pm+1)*sizeof(struct stu));
 if(pm>=si)
 {
  printf("\n contact list is full\n");
  return student;
 }       
 printf("\n please enter the name of student: ");      
 (student+pm)->name = dynamic_input();
 printf("\n please enter the phone number of the student:  ");      
 (student+pm)->phno = dynamic_input();
 printf("\n please enter the email_id of student: ");      
 (student+pm)->email= dynamic_input();
 printf("\n please enter the date of birth details of the student \n");
 printf(" enter year : ");
 scanf("%d",&((student+pm)->dob.year));
 printf(" enter month : ");
 scanf("%d",&(student+pm)->dob.month);
 printf(" enter day : ");
 scanf("%d",&(student+pm)->dob.day);
 printf("enter the following  marks obtained by the student \n");
 printf("tenth class percentage: ");
 scanf("%f",&(student+pm)->marks.tenth);
 printf("twelfth percentage: ");
 scanf("%f",&(student+pm)->marks.twelfth);
 printf("graduation class percentage: ");
 scanf("%f",&(student+pm)->marks.grad);
 printf("enter ID details of the student \n");
 printf("  year of joining: ");
 scanf("%d",&(student+pm)->id.year);
 printf("  series code: ");
 scanf("%s",(student+pm)->id.series);
 pm++;
 printf("\n the value of pm at the end =%d",pm);
 return student;
}

 char* itoa(int n)
{
 printf("\n in itoa\n");
 int i,size;
 char *num,*rev=0;
 //num=0;
 num=calloc(0,1);
 //printf("\n %lu",num);
 for(i=0;n>0;i++)
 {
  num[i]=48+(n%10);
  printf("\n in itoa3\n");
  num=realloc(num,1+i);
  n/=10;
  printf("\ni=%d,n=%d\n",i,n);
 }
 rev=calloc(0,strlen(num)+1);
 for(i=0;i<strlen(num);i++)
 rev[i]=num[strlen(num)-i-1];
 printf("\nin function:rev=<%s>num=<%s>",rev,num);
 free(num);
 return rev;
}
 
/* void dtoa(double n)
{
 char *num;

}*/

 void * dynamic_input()
{
  char *p=0;
  int i=0;
do{
   p=realloc(p,i+1);
   p[i]=getchar();
  }while(p[i++]!='\n');
  p[i-1]=0;
 return p;
}

void* delete(struct stu*p)
{
 int *a,in;
 printf("\n DELETER: \n");
 a=search(p);
 if(a[0]==1)
  return p;
 else
 do{
    if(in>a[0]) 
     printf("\n you have entered a wrong option");
    printf("\nplease enter the index of the contact to be deleted ");
    scanf("%d",&in);
    in--;
   }while(in>a[0]);
 memmove(p+a[in],p+a[in]+1,(pm-a[in]-1)*sizeof(p[in]));
 pm--;
 p=realloc(p,pm*sizeof(struct stu));
 return p;
}

 int* search(struct stu* st)
{
 int i=0,j,in;
 char key[20];
 char *p;
 static int *a;
 a =realloc(0,pm*sizeof(int));  
 if(st==NULL)
 {
  printf("\n the record is empty \n ");
  return a;
 }
 do{
    if(i>=3)
     printf("\n You have entered a wrong option ");
    printf("\n press   0 to search by name or press 1 to search by phone number or press 2 to search by email id  \n");
    scanf("%d",&i);
   }while(i>=3);

 printf("\n please enter the string to be searched\n");  
 scanf("%s",key);
  if(i==0)
 { 
  for(j=0,in=1;j<pm;j++)
   if(p = strstr((st+j)->name,key))
      a[in++]=j; 
 }
  else if(i==1)
 { 
  for(j=0,in=1;j<pm;j++)
   if(p = strstr((st+j)->phno,key))
      a[in++]=j;
 }
  else 
 { 
  for(j=0,in=1;j<pm;j++)
   if(p = strstr((st+j)->email,key))
    a[in++]=j;
 }

 a[0]=in;
 if(a[0]==1)
 {
  printf("\n Match not found \n");
  return a;       
 }
 printf("SEARCH RESULTS\n");
 for(j=1;j<a[0];j++) 
 {  
  printf("\n%d.|student name:%s | email_id:%s |phone_no: %s | D.O.B %d-%d-%d |",j,(st+a[j])->name,(st+a[j])->email,(st+a[j])->phno,(st+a[j])->dob.day,(st+a[j])->dob.month,(st+a[j])->dob.year);
  printf(" percentages (10th:%.2f 12th:%.2f graduation:%.2f ) student_id: %d%s\n",(st+a[j])->marks.tenth,(st+a[j])->marks.twelfth,(st+a[j])->marks.grad,(st+a[j])->id.year,(st+a[j])->id.series);
 }
 return a; 
}

void sort(struct stu *p)
{
 int i,j,in;
 do{
         if(in>2)
                 printf("\n you have entered a worng input\n");
     printf("\n Press 0 to sort by name or Press 1 to sort by phone no or  Press 2 to sort by email id \n"); 
     scanf("%d",&in);
   }while(in>2);
 if(in==0)
 {  
  for(i=pm-1;i>=0;i--)
   for(j=0;j<i;j++)     
    if(strcmp((p+j)->name,(p+j+1)->name)>0)
      str_swap(p,j,j+1);
 } 
  else if(in==1)
 { 
  for(i=pm-1;i>=0;i--)
   for(j=0;j<i;j++)
    if(strcmp((p+j)->phno,(p+j+1)->phno)>0)
     str_swap(p,j,j+1);
 }
  else
 { 
  for(i=pm-1;i>=0;i--)
   for(j=0;j<i;j++)
    if(strcmp((p+j)->email,(p+j+1)->email)>0)
     str_swap(p,j,j+1);
 }
 return;
}

void reverse(struct stu *p)
{
 int i,cnt;
 for(i=0,cnt=pm-1;i<cnt;i++,cnt--)
     str_swap(p,i,cnt);
 return ;
}
void str_swap(struct stu *a,int x,int y)
{
 struct stu temp,temp2;
 temp=a[x];
 a[x]=a[y];
 a[y]=temp;
 return;
}
 void* fill_list(struct stu *p)
{
 p=realloc(p,0);
 pm=0;
 print(p);
 p = filler(p,"john","johnfast@gmail.com","12345678",16,"vhe",5,10,2003,67.8,88.9,76.4);
 p = filler(p,"peter","peter_123@gmail.com","+910000000",15,"vhe",6,11,2001,77.9,83.9,80.4);
 p = filler(p,"dan","dan_smith@gmail.com","040 34567777",14,"vce",7,12,1990,86.4,90.0,84.7);
 p = filler(p,"roger","rogermiles@gmail.com","9000450023",13,"vbe",8,1,2008,60.8,61.9,66.4);
 print(p);
 return p; 
}
 void* filler(struct stu* stud,char *name,char *email,char *phno,int id_year,char *series,int day,int month,int year,float tenth,float twelfth,float grad)
{
 stud=realloc(stud,(pm+1)*sizeof(struct stu));
 (stud+pm)->name= realloc(0,strlen(name)+1);
 strcpy((stud+pm)->name,name);
 (stud+pm)->phno= realloc(0,strlen(phno)+1);
 strcpy((stud+pm)->phno,phno);
 (stud+pm)->email= realloc(0,strlen(email)+1);
 strcpy((stud+pm)->email,email);
 (stud+pm)->id.year=id_year;
 strcpy((stud+pm)->id.series,series);
 (stud+pm)->dob.year=year;
 (stud+pm)->dob.month=month;
 (stud+pm)->dob.day=day;
 (stud+pm)->marks.tenth=tenth;
 (stud+pm)->marks.twelfth=twelfth;
 (stud+pm)->marks.grad=grad;
 pm++;
 return stud;
}
