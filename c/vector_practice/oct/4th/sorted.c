//sorting functions
 #include"sorted.h"
 	#include<stdio.h>
 /*void printa(int*a ,int n);
 void scana(int*a, int n);
 void s_sort(int*a,int n);
 void swap (int*a,int i,int k);
 void b_sort(int*,int);
*/	
  void  printa(int*a,int n)
 {
  printf("\nthe elements present in the array are: \n");
 
  for(int i=0;i<n;i++)
  {
     printf("\t %d",a[i]);
  }
  printf("\n");
 }


  void scana(int*a,int n)
 {
  printf("\nplease enter %d numbers:  ");
 
  for(int i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
   printf("\n");
 }

  void s_sort(int*a,int n)
 { 
  int min;	 
  for(int k=0;k<n-1;k++)
  {
     min = k;		  
    for(int i=k;i<n;i++)
   {	   
     if(a[i] < a[min])
    {
      min = i;  
    }
   } if(min!=k)    
      swap(a,min,k);  
   
    printf("the array values after sort no %d \n ",k+1);
    printa(a,n);
  }
 }

  void b_sort(int*a,int n)
 {

  for(int k=0;k<n-1;k++)
  {	for(int i=0;i<n-k-1;i++)
	  { 
             if(a[i]>a[i+1])
	    {
		    swap(a,(i+1),i);	 
	    }
	  }
  }
 }

  void swap (int*a,int i,int k)
 {
     a[k]=a[k]+a[i];
     a[i]=a[k]-a[i];
     a[k]=a[k]-a[i]; 
 }





