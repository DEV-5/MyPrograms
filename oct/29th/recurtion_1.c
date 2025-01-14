#include<stdio.h>
int sumofnumber(int no);
 int main()
{
  int no,sum;
  printf("\n please enter a number: ");
  scanf("%d",&no);
  sum=sumofnumber(no); 
  printf(" the sum of numbers of %d is %d\n",no,sum);
}       

int sumofnumber(int no)
{
   if(no==0)
   return 0;
        
      return no+sumofnumber(no-1);
}
