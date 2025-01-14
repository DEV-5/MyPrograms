
 #include<stdio.h>

 #define r 2 
 #define c 2
 #define l 2 
  void news(int a[][c][l]);
  
   
    int main()
  {
    int arr[r][c][l] = {9,8,7,6,5,4,3,2};
   
    news(arr);
   
    return 0;
  } 
  
   void news(int a[][c][l])
  {
   
    printf("\ndata present in the array is :");    
   
   int i,j,k;
   
    for(i=0;i<r;i++) 
   {
   
      for(j=0;j<c;j++)
     {
         for(k=0;k<l;k++)
        {    
         printf("\n  \t \t  A(%d,%d,%d) =  ",i,j,k);
          
         printf(" %d ",*((**a)+(i*c)+(j*l)+k));     
        }    
      }
    }
     printf("\n\n");
   }
   
   
  
  
  
