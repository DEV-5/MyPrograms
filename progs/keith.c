
//DATE:28-11-16
//program to input set of number and test if thye are keith numbers
 #include <stdio.h>
 #include<stdlib.h>
void test (int );
//void keith(int *nu,int num,int max);

 int main() 
{
 int i,T,*num;
 printf(" please enter the no test cases: ");
 scanf("%d",&T);
 num=calloc(T,sizeof(int));
 for(i=0;i<T;i++)
  scanf("%d",num+i);
 for(i=0;i<T;i++)
 {
  //printf("\n the number %d is ",num[i]);  
  test(num[i]);
 } 
 return 0;
} 
 void test(int num)
{
   int *nu;
   int *n,i,j,var=num;
  for(i=0,n=0;var;i++)
 {
  n=realloc(n,(1+i)*sizeof(int));
  n[i]=var%10;
  var/=10;
 }
 var=i;
 nu=realloc(0,(var)*(sizeof(int)));
 for(j=0;j<var;j++,i--)
  nu[j]=n[i-1];
 free(n);
 for(i=0;i<var;i++)
  printf("\n %d ",nu[i]);
 printf("\n num=%d,var=%d\n",num,var);
 for(j=var;nu[j-1]<num;j++)
 {
  nu=realloc(nu,(j+1)*sizeof(int));
  nu[j]=0;
  printf("\n (j-max)=%d, j=%d )\n",j-var,j);
  for(i=(j-var);i<j;i++)
  {  
   nu[j]+=nu[i];
      printf("\n nu[%d]=%d\n",j,nu[j]);
  }
  if(nu[j]==num){printf("%d is a keith number\n",num);free(nu); return; };
 }
 //free(nu);
 printf("%d is not a keith number it is not present in the series\n\t",num);
 for(i=0;i<j;i++)
      printf("%d,",nu[i]);
}

/*
 void test(int num)
{
   int *nu;
   int *n,i,j,var=num;
  for(i=0,n=0;var;i++)
 {
  n=realloc(n,(1+i)*sizeof(int));
  n[i]=var%10;
  var/=10;
 }
 var=i;
 nu=realloc(0,var*(sizeof(int)));
 for(j=0;j<var;j++,i--)
  nu[j]=n[i-1];
 free(n);
 for(i=0;i<var;i++)
  printf("\n %d ",nu[i]);
 printf("\n num=%d,var=%d\n",num,var);
 keith(nu,num,var);
}
 void keith(int *nu,int num,int max)
{
 int i=0,j;
 for(j=max;nu[j-1]<num;j++)
 {
  nu=realloc(nu,j+1);
  printf("\n (j-max)=%d, j=%d )\n",j-max,j);
  for(i=(j-max);i<j;i++)
  {  
   nu[j]+=nu[i];
   printf("\n nu[%d]=%d\n",j,nu[j]);
  }
  if(nu[j]==num){printf(">>>>>>>>>>>>>>a keith number\n"); return; };
 }
 //free(nu);
 printf("not a keith number\n");
}
*/

