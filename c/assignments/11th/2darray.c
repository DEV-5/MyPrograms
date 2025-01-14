//DATE:5+11=16
//Def: write a program to calculate grade of student for a given set of exams and also diplay students with lowest and higest average marks. 

#define c 10
#define r 10
int scanf(const char*,...);
int printf(const char*,...);
#include<stdlib.h>
#include<unistd.h>

void init(int m[][c]);
void print_a(int m[][c],int *p);
int highest(int *p);
int* total(int m[][c]);
void graduation(int *t);

int main()
{
 int h,marks[r][c],*tot;
 srand(getpid());
 init(marks);
 system("clear");
 tot=total(marks);
 h = highest(tot);
 print_a(marks,tot);
 printf("HIGHEST : %d",h);
 graduation(tot);
 return 0;
}

void init(int m[][c])
{
 int i,j;
  for(i=0;i<r;i++)
      for(j=0;j<c;j++)
         m[i][j]=rand()%101;
 return;
}

 void print_a(int m[][c],int p[])
{
 int i,j;
 printf("\n");
 for(i=0;i<40;i++,printf("<>"));
 printf("\n\t    |SUB1|SUB2|SUB3|SUB4|SUB5|SUB6|SUB7|SUB8|SUB9|SU10|TOTAL|\n");
 for(i=0;i<80;i++,printf("*")); 
 printf("\n");
 for(i=0;i<r;i++,printf(" %d |\n",*(p+i-1)))
 { 
   printf(" student%3d:|",i+1);
    for(j=0;j<c;j++)
         printf("%4d|",m[i][j]);
 }
 printf("\n");
 for(i=0;i<40;i++,printf("<>"));
  printf("\n");
  return;
}

void graduation(int *t)
{
 int i,a,b,C,d,f;
  for(i=0,a=0,b=0,C=0,d=0,f=0;i<r;i++)
     if((*(t+i)/10)>=80)
            a++;
    else if((*(t+i)/10)>=65)
            b++;
    else if((*(t+i)/10)>=50)
            C++;
    else if((*(t+i)/10)>=35)
            d++;
    else  
            f++;

  printf("\n\t************ CLASS REPORT *************\n");
  printf("\n\t NO OF STUDENTS WITH A GRADE (80 or more) ARE %d",a);  
  printf("\n\t NO OF STUDENTS WITH B GRADE (65 or more) ARE %d",b);  
  printf("\n\t NO OF STUDENTS WITH C GRADE (50 or more)ARE %d",c);  
  printf("\n\t NO OF STUDENTS WITH D GRADE (35 or more)ARE %d",d);  
  printf("\n\t NO OF STUDENTS WITH E GRADE (less than 35)ARE %d\n",f);  
 for(i=0;i<80;i++,printf("*")); 
 printf("\n");
       
}
 int highest(int *p)
{
 int i,j=0,max;       
 for(i=0;i<r;i++,p++) 
    if(*p >= max)
    {   max = *p; 
        j = i;    
    //   printf("student %d has max of %d\n",i+1,max);
    }
     return *(p-r+j);
}
 
 int* total(int m[][c])
{
 static int a[r];
 int i,j;
  for(i=0;i<r;i++)
      for(j=0;j<c;j++)
        a[i]+=m[i][j];
   return a;
}

