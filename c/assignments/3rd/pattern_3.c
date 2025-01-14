
 //DATE:14-10-16
 //program to obtain the bellow patern

 //   0
 //   0 1
 //   0 1 0
 //   0 1 0 1
 //   0 1 0 1 0
 //   0 1 0 1 0 1  
 


 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
 
 int main()
 { 
   int n,i,j,a=0;
   system("clear"); 
   printf("\nplease enter  the  number of itterations :  ");
   scanf("%d",&n);
   for(i=0;i<n;i++,printf("\n"))
	   for(j=0;j<i;j++)
	   { 
	     a = (j%2)==0? 0:1;		
              printf(" %d",a);	
	   }   
   return 0;
 }
