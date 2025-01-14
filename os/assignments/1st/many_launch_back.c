
//DATE:18-12-16
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char** argv)
{
 int i=1;
 char*samp=0;
  while(--argc)
 {
  samp = realloc(samp,strlen(argv[i])+2);
  strcpy(samp,argv[i++]);
  strcat(samp,"&");
  system(samp);
  free(samp);
 }
}
