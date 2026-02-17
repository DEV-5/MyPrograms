
//DATE:4-1-17
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
 int fd,i;
 char bag[10]="zyxwvutsrq",ch;
 struct flock lvar;
 fd=open("test.txt",O_RDWR|O_CREAT,0666);
 lvar.l_type=F_RDLCK; //set a write lock
 lvar.l_whence=0;// start from the begining
 lvar.l_start=0;// 
 lvar.l_len=0;
 printf("press any key to continue");
 getchar();
 //fcntl(fd,F_SETLKW,&lvar);
 //getchar();
 for(i=0;i<3;i++)
 {
  printf("inside file_lock_rd2 reading from file ch=%c...\n",ch);
  read(fd,&ch,1); 
  sleep(1);
 }

 lvar.l_type=F_WRLCK; //set a write lock
 if(fcntl(fd,F_GETLK,&lvar)!=-1){
 printf("the process is being blocked by:%d\n",lvar.l_pid);lvar.l_type=F_WRLCK;}
 fcntl(fd,F_SETLKW,&lvar);
 for(i=0;i<4;i++)
 {
  printf("trying to write.....\n");
  write(fd,"wallet",6);
  printf("writing succesful\n");
 }
 lvar.l_type=F_UNLCK;
 fcntl(fd,F_SETLKW,&lvar);
}
