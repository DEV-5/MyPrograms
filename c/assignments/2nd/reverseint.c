
 //DATE:14-10-16
 //program to reverse an integer entered by the user

 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
 
 int main()
 { 
   int sum,no,temp;
   system("clear"); 
   printf("\nplease enter  a number:  ");
   scanf("%d",&no);
   for(temp=no,no=0;temp;temp/=10)
   no= (no*10)+temp%10;
   printf("\nthe reverse of the entered is%5d \n",no);
 }
