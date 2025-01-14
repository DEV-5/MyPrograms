
//DATE:18-10-16
// program to  implement the design bellow

// *       *
// * *   * *
// * * * * *
// * *   * *
// *       *

 int printf(const char *,...);
 int system(const char *(clear));
 int scanf(const char *,...);

  int main ()
 {
  int no,i,j,t,u;
  system("clear");
  printf("please enter a number\n");
  scanf("%d",&no);

   for(i=-no;i<=no;i++,printf("\n"))
   {
       //printf("value of i is %*d\n",3,i);
       u = (i<0)?-i:i;
	   for(j=-no;j<=no;j++)
	  {
         t = (j<0)?-j:j;
	   if(t+1>u)
       {
       printf("* ");
       // printf("In if t=%d (no-j)=%d \n",t,(no-j));
       }
       else
       {
       printf("  ");
       //printf("In else t=%d (no-j)=%d \n",t,(no-j));
       }
      }
   }
    return 0;
 }

