//DATE:1-11-16
//Purpose: Generate a mark array with random marks for all students and 
//determine the grade for each student and dtermine the student with the highest marks. 
#include<stdlib.h>
#include<unistd.h>
#define s 20
int printf(const char*,...);
int scanf(const char*,...);
int system(const char*(clear));

void grade(int []);
void find_high(int[]);
void print(int stu[]);
void insert(int stu[]);

 int main()
{
  int i;
  int stu[s];
  system("clear");
  srand(getpid());
  insert(stu);
  print(stu);
  grade(stu);
  find_high(stu);

}

void grade(int ar[])
{
  int a=0,b=0,c=0,d=0,f=0,i;
  for(i=0;i<s;i++)
  {
    //Switch case offers faster exection than elseif when no of cases are more than 5
    if(ar[i]>80)// A grade
            a++;
    else if(ar[i]>70)//B grade
            b++; 
    else if(ar[i]>60)//C grade
            c++;
    else if(ar[i]>40)//D grade        
            d++;
    else
            f++;
  }
  printf("\n\n\t *******CLASS REPORT*******");
  printf("\n\t> students with A grade: %d",a);
  printf("\n\t> students with B grade: %d",b);
  printf("\n\t> students with C grade: %d",c);
  printf("\n\t> students with D grade: %d",d);
  printf("\n\t> students with F grade: %d\n",f);
}

 void find_high(int ar[])
{
 int i,b,greatest=0,arr[s];
 for(i=1,b=0;i<s;i++)
 {
  if(ar[greatest]==ar[i])
  { 
   b++;
   arr[b]=i;
  }
  else if(ar[greatest]<ar[i])
  {
   b=0;       
   greatest=i;
   arr[b]=i;
  }
 }
  printf("\n The greatest value %d is present in the following index: ",ar[greatest]);
  for(i=0;i<=b;i++)
          printf("%d ,",arr[i]);    

  printf("\n");
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
}

void insert(int stu[])
{
  int i;      
  for(i=0;i<s;i++)
          stu[i]=rand()%101;
}
