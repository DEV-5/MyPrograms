    
 //DATE: 14-10-16
 //program to find the sum of the digits

 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
  int main()
 { 
   int sum,no,temp;
   system("clear"); 
   printf("\nplease enter  a number:  ");
   scanf("%d",&no);
   for(temp=no,sum=0;temp;temp/=10)
      sum+=temp%10;
   printf("\nthe sum of digits of %d is %d\n",no,sum);
 }
