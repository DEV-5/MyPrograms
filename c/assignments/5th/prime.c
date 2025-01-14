//Purpose: Determine whether a given number is prime or not
//
int printf(const char*,...);
int system(const char*(clear));
int scanf(const char*,...);

 int prime(int no);
 int root(int num);
 int main()
{    int no; 
       system("clear");
       printf("\nenter a number: ");
       scanf("%d",&no);
      if(prime(no))
        printf("%d is an prime number\n",no);      
      else
        printf("%d is not a prime\n",no);
       return 0;
}


  int prime(int no)
 {
  int rt,i;
  rt = root(no);
  
   if(no%2==0)
      return 0;    
  for(i=3;i<=rt;i+=2)
    if(no%i==0)
      return 0;
    
     return 1;  
 }

 int root (int no)
{       int i; 
        for(i=0;(i*i)<=no;i++);
        return --i;
}
