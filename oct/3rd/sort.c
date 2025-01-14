
 #include<stdio.h>
 
 void printa(int*a ,int n);
 void scana(int*a, int n);
 void sel_sort(int*a,int n);
 void bubble_sort(int list[], int n);
 
  int main ()
 {
  int n=9;	 
  int a[]={1,2,3,4,5,6,7,8,9};
  scana(a,n);
  printa(a,n);
  sel_sort(a,n);
// bubble_sort(a, n);
  printa(a,n);
    
  return 0;
 }


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

  void sel_sort(int*a,int n)
 {
  for(int k=0;k<n-1;k++)
  {	  
    for(int i=k;i<n;i++)
   {
     if(a[i]<a[k])
    {
     a[k]+=a[i];
     a[i]=a[k] - a[i];
     a[k]-=a[i];  
    }	    
   }
    printf("the array values after sort no %d \n ",k);
    printa(a,n);
  }
 }

 /* void in_sort(int*a,int n)
 { 
  for(int i=0;i,n;i++)
  {
   
  }
 }




void bubble_sort(int list[], int n)
{
	  int c, d, t,f;
	   
	    for (c = 0 ; c < ( n - 1 ); c++)
		      {
			          for (d = 0 ; d < n - c - 1; d++)
					      { f++;
						            if (list[d] > list[d+1])
								          {
										        
										   
										          t         = list[d];
											          list[d]   = list[d+1];
												          list[d+1] = t;
													        }
							        }
				    }
	    printf("\n net code loops:%d",f);
}*/









