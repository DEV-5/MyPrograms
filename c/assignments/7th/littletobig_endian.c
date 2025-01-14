
//DATE:25-10-16 
//program to test if data is little endian and if little convert it to big endian 


  int printf(const char*,...);
  int scanf(const char*,...);
  int system(const char*(clear));
  

   int main()
  {
   short int no;
   char *p,temp;

   printf("\nplease enter a number: ");
   scanf("%d",&no);
   printf("the Hex equivalent of the no is %x\n",no);
   p=(char*)&no;
   printf("*p=%x *(p+1)=%x \n",*p,*(p+1));
   temp=*(p+1);
   *(p+1)=*p;
   *p=temp;
   printf("the Hex equivalent of the no is %x\n",no);
   return 0;
  }
