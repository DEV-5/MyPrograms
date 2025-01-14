
#include<stdio.h>

void bin_equivalent(int no,int bit);//function prototype

int main()
{
 int no;
 printf("please enter  a number  whos binary equivalent: ");
 scanf ("%d", &no);
 bin_equivalent(no,32);
 return 0;
}



 void bin_equivalent(int no,int bit)
{
        if(bit==-1)
        return ;
 printf("%d",(no>>bit)&1);
 return bin_equivalent(no,bit-1);
}
