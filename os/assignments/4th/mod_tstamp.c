
//DATE: 1-1-17
//DATE: 2-1-17
//DATE: 3-1-17
#include<stdio.h>
#include<stdlib.h>
//#include<dirent.h>
#include<sys/types.h>
#include<sys/time.h>
#include<utime.h>
#include<sys/stat.h>
#include<time.h>
//#include<utime.h>

 int main(int argc,char** argv)
{
 int a=1,b=1;
 char datestr[20],timestr[20];
 struct stat stu1,stu2;
 if(argc!=3){printf("you have entered wrong number of arguments\n");return 0;}
 system("ls -l");
 struct utimbuf tu;
 long int ti1,ti2;
 tu.actime=0;
 //ti.modtime=0;
 struct timeval tm[2];
 stat(argv[1],&stu1);
 stat(argv[2],&stu2);
 ti1=stu1.st_atime;
 ti2=stu2.st_atime;
 printf("%s\n",ctime(&(stu1.st_ctime)));
// printf("%s:%ld\n",argv[1],stu1.st_ctime);
// printf("%s:%ld\n",argv[2],stu2.st_ctime);
 printf("%s:%ld\n",argv[1],ti1);
 printf("%s:%ld\n",argv[2],ti2);
 if(stu1.st_atime>stu2.st_atime) 
 { 
  printf("\n%s is older than %s\n",argv[2],argv[1]);
  tu.actime =ti1;
  tu.modtime =stu1.st_mtime;
  utime(argv[2],&tu);
 // tm[0].tv_sec= stu1.st_ctime;
 // utimes(argv[2],&tm[0]);
 }
 else if(stu1.st_atime<stu2.st_atime)
 {
  printf("\n%s is older than %s\n",argv[1],argv[2]);
  tu.actime = ti2;
  tu.modtime =stu2.st_mtime;
  utime(argv[1],&tu);
 // tm[0].tv_sec=stu2.st_ctime;
 // utimes(argv[1],&tm[0]);
 }
 else printf("both are equally old\n");
 system("ls -l");
 return 0;
}
