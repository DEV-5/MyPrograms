
//DATE:30-12-16
#include<stdio.h>
//#include<sys/stat.h>
//#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
 
int main(int argc,char **argv)
{
 int fd1,fd2,size;
 char *buf;
 if(argc!=3){printf("you have enter wrong no of arguments\n");return 0;}
 fd1=open(argv[1],O_RDONLY);
 if(fd1==-1){printf("source file is empty\n");return 0;}
 fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600);
 size=lseek(fd1,0,SEEK_END);
 lseek(fd1,0,SEEK_SET);
 printf("hello size:%d\n",size);
 getchar();
 close(1);
 close(0);
 fcntl(fd1,F_DUPFD,0);
 fcntl(fd2,F_DUPFD,1);
 buf=malloc(size);
 while(read(fd1,buf,size))
    write(fd2,buf,size);
}
