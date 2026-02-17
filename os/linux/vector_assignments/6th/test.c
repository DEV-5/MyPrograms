
//DATE:30-12-16

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 int main()
{
 int p[2];
 pipe(p);
  char ch;
 if(fork==0)
 {
  while(1)
  sleep(1);
  while(1)
  {
   read(p[0],&ch,1);
   printf(" ");
  }
 }
 else 
 {
  int i=1;
  while(1)
  {
   write(p[1],&ch,1);
   printf("count:%d\n",i++);
  }
 }
}
