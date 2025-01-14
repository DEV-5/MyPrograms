
//date:5-10-2016
//conditional operator based assignment
//enter a char and if the char is lower case convert it to upper case
 #include<stdio.h>


  int main ()
 {
  char a;
  printf("enter a char value:  ");
  scanf("%c",&a);
   (a>='a'&&a<='z')?a-=32 : 0;
   printf("the data entered is %c\n",a);
   return 0;
 }
