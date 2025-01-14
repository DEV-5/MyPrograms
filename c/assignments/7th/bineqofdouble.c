
 //date:25-10-16
 //program to print the binary equivalent of double
 
  int printf(const char*,...);
  int scanf(const char*,...);
  int system(const char*(clear));
  
  int main()
 {
  int bit;
  long int *p,no; 
  double d;
      
  printf("\n Enter a Double data whose binary is to be printed: ");
  scanf("%f",&d);
  p=(long int*)&d;
  no =*p;
  printf("\t");
  for(bit=31;bit>=0;bit--)
         printf("%d",(no>>bit)&1); 
  printf("\n\n");
  //printf("%x\n",no);
  printf("the size of int pointer is %d \n",sizeof(p));
  return 0;
 }
