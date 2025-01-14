
 #include<stdio.h>
 
 void main ()
 {
  int *a,b;
  a=&b;
  *a=45;

  
  printf("\nthe value of a is %d \n\n",*a);
  
  return;
 }
