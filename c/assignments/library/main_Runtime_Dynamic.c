//Date 27th sept 2020
#include <stdio.h>
//#include <math.h>
#include <dlfcn.h>

int add(int,int);
double div(int,int);

int main()
{
    double a=25,b=2;
    char astr[5];
    //double res=0;
    void * handle = NULL;
    double (*powfn)(double,double);
    printf("there is no spoon \n");
    //sum=add(a,b);
    //res=div(a,b);
    //handle = dlopen("libmath.so",RTLD_NOW);
    handle = dlopen("/lib/libm.so.6",RTLD_NOW);
    if(handle == NULL){printf("dlopen failed to open lmath\n");return 1;}
    powfn = dlsym(handle, "pow");
    printf(" %lf ^ %lf= %lf  \n",a,b,powfn(a,b));
    scanf("%s",astr);
    dlclose(handle);
}
