
//prog new
int printf(const char*,...);
int main()
{  
 printf("please \rread\nthis\fwith a grain of salt\v\f");
 //printf("\f");
 //printf("\b\b\r");
}

/*// PROGRAM 1
 #include <stdio.h>
 int f1() { printf ("Geeks"); return 1;}
 int f2() { printf ("forGeeks"); return 1;}
 int main()
 {
 int p = f1() + f2();
 return 0;
 }

 // PROGRAM 2
 #include <stdio.h>
 int x = 20;
 int f1() { x = x+10; return x;}
 int f2() { x = x-5; return x;}
 int main()
 {
 int p = f1() + f2();
 printf ("p = %d", p);
 return 0;
 }
*/

 // PROGRAM 3
/* #include <stdio.h>
 int main()
 {
 int i = 8;
 int p = i++*i++;
 int g = i+i++*i;
 printf("p:%d and g:%d\n",p,g);
 }
#include<stdio.h>
#include<stdlib.h>
    int main()
    {
     int x = 1,i=0,y;
     y=i+i++;
     printf("value of y is %d\n",y);
     if(x++ && (x==1))
	puts("yes\n");
     else
	puts("no"); 
     return 0;	     
    }*/
