
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

void connected_to(struct sockaddr_in addr);

 int main(int argc,char** argv)
{
 int sfd,on=1;
 sfd=socket(AF_INET,SOCK_STREAM,0);
 if(sfd<0){perror("socket");return 0;}
 if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
 {perror("setsockopt");return 0;}
 puts("setsockopt success");
 struct sockaddr_in saddr;
 saddr.sin_family=AF_INET;
 saddr.sin_port=htons(atoi(argv[1]));
 saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
 if(bind(sfd,(const struct sockaddr*)&saddr,sizeof(saddr))<0)
 {perror("bind");return 0;}
 puts("bind success");
 if(listen(sfd,1)<0)
 {perror("listen");return 0;}
 puts("listen success");
 struct sockaddr_in caddr;
 int cfd,size=sizeof(caddr);
 char buf[100];
 cfd=accept(sfd,(struct sockaddr*)&caddr,&size);
 if(cfd<0){perror("accept");return 0;}
 printf("a client with ");
 connected_to(caddr);
 puts(" has joined !");
 if(recv(cfd,buf,100,0)<0)
 {perror("recv");return 0;}
 puts("recive success");
 puts(buf);
 strcpy(buf,"thanks for sending the message");
 if(send(cfd,buf,100,0)<0)
 {perror("send");return 0;}
 puts("send success");
 return 0;
}

void connected_to(struct sockaddr_in addr)
{
 printf("ipv4 address=%s and port_no=%d",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
}
