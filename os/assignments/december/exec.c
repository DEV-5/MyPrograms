
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
// system("time");
 char *p[]={"ls","-l","-i","-t",NULL};
 printf("pid:%dis a child of=%d\n",getpid(),getppid());
 system("date");
 //sleep(4);
 execvp("ls",p);
 printf("end of program\n");
 //system("time");
}
