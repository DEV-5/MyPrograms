
//DATE:28-12-16
#include<stdio.h>
//#include<stdlib.h>
//#include<dirent.h>
#include<sys/types.h>
#include<utime.h>
#include<sys/stat.h>
#include<time.h>

 int main(int argc,char** argv)
{
 int a=1,b=1;
 char datestr[20],timestr[20];
 struct stat stu1,stu2;
 if(argc!=3){printf("you have entered wrong number of arguments\n");return 0;}
 //struct utimbuf ti1,ti2;
 stat(argv[1],&stu1);
 stat(argv[2],&stu2);
 printf("%s\n",ctime(&(stu1.st_ctime)));
 printf("%s:%d\n",argv[1],stu1.st_ctime);
 printf("%s:%d\n",argv[2],stu2.st_ctime);
 if(stu1.st_ctime>stu2.st_ctime) 
	 printf("\n%s is older than %s\n",argv[2],argv[1]);
 else if(stu1.st_ctime<stu2.st_ctime)
	 printf("\n%s is older than %s\n",argv[1],argv[2]);
 else printf("both are equally old\n");
 //a=utime("test.c",&ti1);
// b=utime(argv[2],&ti2);
 //printf("timestamp:(a=%d,b=%d)|%s:%d|%s:%d|\n",a,b,"time",(long int)ti1.actime,argv[2],(int)ti2.modtime);
 return 0;
}
