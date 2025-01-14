//DATE:16-10-16
//program to implement th below pattern

// * * * * *
//  * * * *
//   * * *
//    * *
//     *
//    * *
//   * * *
//  * * * *
// * * * * *

 int printf(const char *,...);
 int system(const char *(clear));
 int scanf(const char *,...);

  int main ()
 {
  int no,i,j,t;
  system("clear");
  printf("please enter a number\n");
  scanf("%d",&no);

   for(i=-no+1;i<=no-1;i++,printf("\n"))
   {

      t= (i<0)?-i:i;

	  for(j=no;j>=0;j--)
	  {
		if(t>=j)
       printf("* ");
      else
	   printf(" ");
     }
   }
   return 0;
 }
