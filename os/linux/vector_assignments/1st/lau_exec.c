
//DATE:18-12-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

 int main(int argc,char** argv)
{
    //char **samp;
    //int temp=1; 
    int i=0;
    memmove(argv,argv+1,(argc-1)*sizeof(char*));
    argv[argc-1]=0;
    while(argv[i])
    printf("%s\n",argv[i++]);
    execvp(argv[0],argv);
} 
/*int main(int argc,char** argv)
{
 char **samp;
 int temp=1;
 samp= calloc(argc,sizeof(char *));
 while(--argc)
   samp[argc-1]=argv[argc];	 
 execvp(argv[1],samp);
}*/
