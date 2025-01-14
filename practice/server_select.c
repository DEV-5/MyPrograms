#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h> 
#include<string.h>
#include<sys/socket.h>
#include<sys/select.h>
#include<netinet/in.h>

void conneted_to(struct sockaddr_in );

int main(int argc,char** argv)
{
 int sfd,on=1;
 sfd=socket(AF_INET,SOCK_STREAM,0);
 if(sfd<0)
 {perror("socket");return 0;}
 if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)))
 {perror("socket");return 0;}
 struct sockaddr_in saddr;
 int size=sizeof(saddr);
 saddr.sin_family= AF_INET;
 saddr.sin_port= htons(atoi(argv[1]));
 saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
 if(bind(sfd,(const struct sockaddr*)&saddr,size)<0)
 {perror("bind");return 0;}
 if(listen(sfd,1)<0)
 {perror("listen");return 0;}
 struct sockaddr caddr;
 char buf[100];
 int newfd,maxfd,fd,i,ret,clen=sizeof(struct sockaddr);
 fd_set  rfds,testfds;
 FD_ZERO(&rfds);
 FD_ZERO(&testfds);
 FD_SET(sfd,&rfds);
 while(1)
 {
  testfds=rfds;
  ret=select(sfd,&rfds,NULL,NULL,NULL);
  if(ret<0){perror("select");return 0;}
  for(fd=0;fd<100;fd++)
  {
   if(FD_ISSET(fd,&testfds))
   {
    if(sfd==fd)
    {
    newfd=accept(sfd,(struct sockaddr*)&caddr,&clen);
    } 
   }
  }
 }


 //for()
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 /*
 int ret,newfd,fd,maxfd,cnt=0;
 fd_set rfds,testfd;
 FD_ZERO(&rfds);
 FD_SET(sfd,&rfds);
 maxfd=sfd;
 while(1)
 {
  
 }
 if(accept(sfd,(struct sockaddr*)&caddr,&size)<0)
 {perror("accept");return 0;}*/
}

void conneted_to(struct sockaddr_in addr)
{
 printf("ipv4 address=%s and port_no=%d",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
}

