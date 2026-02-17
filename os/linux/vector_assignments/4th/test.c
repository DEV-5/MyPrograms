
//DATE:28-12-16
//DATE:18-04-18
#include<stdio.h>
//#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

 int main(int argc,char** argv)
{
 DIR * dr;
 struct dirent *d;
 if(argc!=2){printf("you have entered wrong number of arguments\n");return 0;}
 dr=opendir(argv[1]);
 //dr=opendir("dam");
 if(dr==NULL){perror("opendir");return 0;}
 printf("this works argv[1]=%sthe value of the ptr returned by opendir is:%d|\n",argv[1],dr);
 d = readdir(dr);
 printf("\nthis works\n");
 printf("inode number:%d || name:%s\n",(int)d->d_ino,d->d_name);
 closedir(dr);
 return 0;
}
