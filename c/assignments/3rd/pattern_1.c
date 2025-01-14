
 //DATE:14-10-16
 //program to obtain the bellow patern

 //  ******
 //  *****
 //  ****
 //  ***
 //  **
 //  *


 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
 
 int main()
 { 
   int n,i,j;
   system("clear"); 
   printf("\nplease enter  the  number of itterations :  ");
   scanf("%d",&n);
   printf("\n\t"); 
   for(i=0;i<n;i++,printf("\n\t"))
	   for(j=0;j<n-i;j++)
		   printf(" *");
   return 0;
 }
