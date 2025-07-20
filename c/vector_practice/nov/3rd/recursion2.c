
#include<stdio.h>
long int bin_equivalent (int no);
int main()
{
 int no;
 long int ans;
 printf("please enter  a number  whos binary equivalent: ");
 scanf("%d", &no);
 ans=bin_equivalent(no);
 printf("\nthe bin equivalent of %d is %ld\n",no,ans);
 return 0;
}
long int bin_equivalent(int no)
{
 if(no==0)
   return 0;
 return (no%2)+(10*bin_equivalent(no/2));
}
