
 #include<stdio.h>
 #include<fcntl.h>
 #include<string.h>
 #include<unistd.h>
int main()
{
 int fd;
 char str[20];
 fd=open("/dev/pts/0",O_WRONLY);
 if(fd==-1){perror("open");return 0;}
 printf("fd= %d its pid:%d \n",fd,getpid());
 while(1)
 {
  printf("enter msg:");
  fgets(str,20,stdin);
  write(fd,str,strlen(str));
  if(strstr(str,"quit")) break;
 }
}
