
#include<stdio.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>

 int main(int argc,char** argv)
{
 puts("this is a test ");
 int fd;FILE *fp;
 fd=open(argv[1],O_CREAT|O_RDWR,0666);
 fp= mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
 {perror("mmap");return 0;}
 char buf[]="this is a test file and it works";
 fputs(buf,fp);
}

