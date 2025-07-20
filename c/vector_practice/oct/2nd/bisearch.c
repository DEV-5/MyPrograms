
//AUTHOR: vasudev
//Progname: bisearch.c
//Discription: implement binary search on an sorted array 

 #include<stdio.h>
 #include<string.h>
 #define N 10;

 int a[]={0,1,2,3,4,5,6,7,8,9};
 char res[4];

 int bisearch (int key);
 char* no (int);

  int main(void)
 {
  int key,ans=0;
  key = system("clear");  	
 printf("%d ",key); 
  printf("\nenter the digit to be searched : ");
  scanf("%d",&key);
 
  ans = bisearch(key);

  if(ans==-1)
	printf("\n\tthe number entered (%d) is not present in the list\n",key);
  else
	printf("\n\t%d is present in %d%s place of the list \n",key,ans,no(ans));  
  return 0;
 }

 
 int bisearch(int key)
{
 int  i=1;	
 int  first=0;
 int  last=N-1;
 int  mid;
 
  while(mid!=last||mid==first)
 {
   mid=(first+last)/2;
   i++;
  if(a[mid]==key)
    return mid;
    
  else if(mid > key)
  {  last = mid-1;
       printf("\tmid(%d)>key(%d) loop no= %d\n",mid,key,i);
  }   
  else
  {    first= mid+1;
       printf("\tmid(%d)<key(%d) loop no= %d\n",mid,key,i);
     i--;	 
 
  }  
 }
  return -1;
}
 

 char* no(int ans)
	
{
    switch (ans)
 {
	case 1:
	 strcpy(res,"st");
	 return res;
	
	case 2:
         strcpy(res,"nd");
	 return res;
        
	case 3:
         strcpy(res,"rd");
	 return res;

	default:
         strcpy(res,"th");
         return res;
 }
}

