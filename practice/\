
//date:26-3-17
//vasudev

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

 int main(int argc,char** argv)
{
 int fd,on=1;
 fd=socket(AF_INET,SOCK_STREAM,0);
 if(fd<0){perror("socket");return 0;}
 puts("socket successfully created");
 struct sockaddr_in saddr;
 saddr.sin_family=AF_INET;
 saddr.sin_port=htons(atoi(argv[1]));
 saddr.sin_addr.s_addr=inet_addr(argv[2]);
 if(connect(fd,(const struct sockaddr*)&saddr,sizeof(saddr))<0)
  {perror("connect");return 0;}
 puts("connect was successful");
 char buf[100];
 
 gets(buf);
 if(send(fd,buf,100,0)<0)
 {perror("send");return 0;}
 puts("send success");
 if(recv(fd,buf,100,0)<0)
 {perror("recv");return 0;}
 puts("reply from the server");
// puts("recive success");
 puts(buf);
 return 0;
}
