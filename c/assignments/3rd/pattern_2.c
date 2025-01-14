
 //DATE:14-10-16
 //program to obtain the bellow patern

 //   * * * * *
 //    * * * *
 //     * * *
 //      * *
 //       *
 


 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
 
 int main()
 { 
   int n,i,j,k;
   system("clear"); 
   printf("\nplease enter  the  number of itterations :  ");
   scanf("%d",&n);
   printf("\t");
   for(i=0;i<n;i++,printf("\n\t"))
   {
	for(j=0; j < i; j++)
          printf(" ");
	     
	for(k=0;k < n-i ;k++)
	   printf("* ");
   }	     	     
   return 0;
 }
