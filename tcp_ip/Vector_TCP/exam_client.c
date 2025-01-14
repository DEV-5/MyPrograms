
#include"myhead.h"

 int main(int argc,char** argv)
{
 if(argc<3){puts("cla format: ./ex_s port server_ip");return 0;}
 int fd;
 fd=socket(AF_INET,SOCK_STREAM,0);
 if(fd<0){perror("socket");return 0;}
 struct sockaddr_in saddr;
 int size=sizeof(struct sockaddr);
 saddr.sin_family= AF_INET;
 saddr.sin_port= htons(atoi(argv[1]));
 saddr.sin_addr.s_addr=inet_addr(argv[2]);
 if(connect(fd,(struct sockaddr*)&saddr,size)<0)
 {perror("connect");return 0;}
 int r,s;
 char buf[100];
 //gets(buf);
 scanf("%s",buf);
 s=send(fd,buf,100,0);
 if(s<0){perror("send");}
 else if(s==0)
 {printf("the server exited abruptly");close(fd);return 0;}

 r=recv(fd,buf,100,0);
 if(r<0){perror("send");}
 else if(r==0){printf("the server exited abruptly");}
 printf("Server sent:%s\n",buf);
 close(fd);
 return 0;
}
