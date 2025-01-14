//DATE: 16th July 2020

#include <stdio.h>
#include <stdlib.h>

//function prototype
double myPow(double, int);
double myPow_vp(double, int);
double vpfn(double x, unsigned int exp);

int main(int argc,char*argv[])
{
    double result = 0;
	if(argc != 3)
	{
        printf("Incorrect usage: pow 2.00 9 \n");
        exit(1);
    }
	result = myPow_vp(strtod(argv[1],NULL),atoi(argv[2]));
    printf("%s^%s = %lf \n",argv[1],argv[2],result);
}

//refined approach
double myPow_vp(double x, int n){
    if(x == 1.0|| n==0)
        return 1;
    double result ;
    unsigned int exp =abs(n);
    printf("exp=%d\n",exp);
    result = vpfn(x,exp);//(2,3) expected:8 //64
    printf("result=%lf\n",result);

    if(n<0) 
       result=1/result;
    return result;
}

double vpfn(double x, unsigned int exp)
{
    printf("x= %lf exp=%d \n",x,exp);
    if(exp==1) return x;

    double result = x;

    for(unsigned int j=2;1;j*=2)//todo
    {
        printf("inside for result= %lf exp=%ld \n",result,j);
        if(j>exp)
        {
            result*=vpfn(x,exp-(j/2));
            return result; 
        }
        result *=result;
        if(j==exp)
            return result;
    }
}

//brute force approach
double myPow(double x, int n){
    //case 1: n is postive + zero
    //case 2: n is negitive    
    if(x == 1.0)
        return 1;
    double result =1;
    unsigned int i =abs(n);
    printf("i=%d\n",i);
    while(i)
    {
        result*=x;
        i--;
    }
    printf("result=%lf\n",result);

    if(n<0) 
       result=1/result;
    return result;
}
