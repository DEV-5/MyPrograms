//Purpose: Print all the prime numbers in a give range

int printf(const char*,...);
int system(const char*(clear));
int scanf(const char*,...);

 int prime(int no);
 int root(int num);
 int check_digit(int no,int digit);

int main()
{    int min,max,digit,no; 
       system("clear");
       printf("\nenter a the min and max range followed by the digit: ");
       scanf("%d %d %d",&min,&max,&digit);
       for(no=min;no<=max;no++)
           if(prime(no)&&check_digit(no,digit))
               printf("%d | ",no);    
       printf("\n");
       return 0; 
}
  int prime(int no)
 {
  int rt,i;
  rt = root(no);
  
   if(no==2)
     return 1; 
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

 int check_digit(int no,int digit)
{
       int i; 
  
   while(no)
  {
    i =no%10;
    no/=10;    
    if(i==digit)
      return 1;
  }
   return 0;
}
