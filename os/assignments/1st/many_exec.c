
//DATE:18-12-16
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

 int main(int argc,char** argv)
{
 char* carray[2];
 int i,ret,status;
 carray[1]=0;
// while(i<argc)

 for(i=1;i<argc;i++)
 {
  ret=fork();
   if(ret==0)
  { 
   carray[0]=malloc(strlen(argv[i])+2);
   strcpy(carray[0],argv[i]);
   //strcat(carray[0],"&");
   printf("%s>|%d|",carray[0],getpid());
   execvp(carray[0],carray);
   if(i!=argc-1) wait(&status);
   i++; 
  }
 }
}


