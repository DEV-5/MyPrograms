
#include<stdio.h>

 void main ()
{
        
    FILE *fp;
    
    fp = fopen("sample.txt","w");
    fprintf(fp,"this is a sample program for files her are the results\n");
    fprintf(fp,"this works\n");
    fclose(fp);
}
