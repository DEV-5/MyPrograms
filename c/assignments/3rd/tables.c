//DATE:15-10-16
//progam to use %*d and %-d

 int system(const char*(clear));
 int printf(const char*,...);
 int scanf(const char*,...);
  int main()
 {
  int no,temp,i,limit,count1,count2,count3;
  system("clear");
  printf("\nplease enter a number :  ");
  scanf("%d %d",&no,&limit);
  for(count1=1,temp=no;temp;count1++,temp/=10);
  for(count2=1,temp=limit;temp;count2++,temp/=10);
  for(count3=1,temp=no*limit;temp;count3++,temp/=10);
  for(i=1;i<=limit;i++)
  {
   printf("\t%-*dx%*d =%*d \n",count1,no,count2,i,count3,no*i);
  } 
   return 0; 
 }

