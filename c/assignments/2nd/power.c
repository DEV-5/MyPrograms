
 //DATE:14-10-16
 //program to find the value of a number raised to its exponent 

 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
 
 int main()
 { 
   int exp,no,power,temp;
   system("clear"); 
   printf("\nplease enter  the  number and its exponent:  ");
   scanf("%d %d",&no,&exp);
   for(temp=exp,power=1;temp;temp--)
    power*= no;
   printf("\n%d^%d = %d \n",no,exp,power);
 }
