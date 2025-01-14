
 #include <stdio.h>

  int main ()
 { 
 char a='a';
 char b='b';
      a+= b;
      printf("temp a=%d\n",a);
      b= a-b;
      printf("temp b=%d\n",b);
      a= a-b;
 printf("\tthe values of a and b are %c %c\n",a,b);
 return 0;
 }
