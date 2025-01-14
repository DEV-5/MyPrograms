
 //author: DEV
 //program name: pytriangle
 
 #define N 5
 int printf(const char* ,...);

  int main()
 {
  int i,j,k;	 
  int a[N],b[N];
  system("clear");

  for(i=0;i<N;i++) 
  {
     printf("\n");
     k=N-i;
     while(k)
    {
     printf(" ");
     k--;
    }
	    for(j=0;j<i;j++)
	    {

	     printf("1 ");
	    }
    }	     
 
   return 0;
  }
 

 
