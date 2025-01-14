
 //DATE:14-10-16
 //program to obtain the bellow patern

 //       *
 //      * *
 //     * * *
 //    * * * *
 //     * * *
 //      * *
 //       *
 


 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
 
 void print(int n,int des);

 int main()
 { 
   int n,i,j,k;
   system("clear"); 
   printf("\nplease enter  the  number of itterations :  ");
   scanf("%d",&n);
   print(n/2,1);
   if(n/2!=(n-(n/2)))
   {  
   // for(i=0;i<;i++)
     // {	    
//	      printf(" ");
  //    }
     for(j=0;j<n-(n/2);j++)
     {
      printf("* ");
     }
     printf("\n");
   }           
   print(n/2,0);
   return 0;
 }

   void print( int n,int  des)
 {
		
	 int i,j,k,d,c;
	for(i=0;i<=n;i++,printf("\n"))
   { 
	   if (des==0)
	     { 
		d=n-i;
		c=i;
             }
             else if(des==1) 
	     {
		 d=i;
                 c=n-i;	 
	     }

	for(j=0; j <c+1; j++)
          printf(" ");
	    
	for(k=0;k < d ;k++)
	   printf("* ");
   }	
 }
