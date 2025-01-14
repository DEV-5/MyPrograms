
//DATE:25-2-17
#include"myhead.h" 
void client_info(struct sockaddr_in caddr);

int main(int argc,char** argv)
{
 if(argc<2)
 {puts("input format: server.exe  well_known_port");return 0;}	
 
 int sfd,on=1;
 puts("creating a server connection"); 
 sfd = socket(AF_INET,SOCK_STREAM,0);//SOCK_STREAM is for tcp
 if(sfd<0){perror("socket");return 0;}
 puts("server socket created");
 puts("config options to avoid error_bind address already in use");
 if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
 {perror("setsockopt");return 0;}
 puts("setsockopt success");
 puts("binding ...");
 struct sockaddr_in saddr;
 saddr.sin_family = AF_INET;
 saddr.sin_port = htons(atoi(argv[1]));
 printf("the value of port is %d\n",saddr.sin_port);
 saddr.sin_addr.s_addr = inet_addr("0.0.0.0");
 if(bind(sfd,(const struct sockaddr*) &saddr,sizeof(saddr))<0)
 {perror("bind");close(sfd);return 0;}
 puts("bind success");
 puts("creating connection queue of only 1");
 if(listen(sfd,1)<0)
 { perror("listen");close(sfd);return 0; }
 puts("listen success");

 char buff[100];
 int ret,newfd,fd,maxfd,cnt=0;
 struct sockaddr_in caddr; int clen = sizeof(caddr);
 fd_set rfds,testfd;
 FD_ZERO(&rfds);
 FD_SET(sfd,&rfds);
 maxfd=sfd;
 while(1)
 {
  testfd=rfds;
  printf("server waiting ...\n");
  printf("max fd:%d\n",maxfd);
  printf("no of clients connected: %d \n",cnt);
  printf(" range of file discriptors: %d<%d\n",sfd,maxfd+1);
  ret=select(100,&testfd,NULL,NULL,NULL);
//the last argument is the time interval select must wait untill time out
//-occurs if null is specified the select waits indefinitely 

//testfds is provided as readfds,select waits until any of the 
//-fds are ready for reading

//nfds= 99+1 ,where 99 is max value of any descriptor.
//ret has the totalnuber of bits set in readfds,writefds,exceptfds
  system("clear");
  if(ret<0){perror("select");}
  else if(ret==0){perror("timeout");}
  for(fd=0;fd<100;fd++)
  {
   if(FD_ISSET(fd,&testfd))//check if fd is part of testfd
   {
    if(sfd==fd)
    {
     newfd = accept(sfd,(struct sockaddr*)&caddr,&clen);
     if(newfd<0){perror("accept");}
     FD_SET(newfd,&rfds);
     cnt++;
     maxfd=(newfd>maxfd)?newfd:maxfd;
     puts("new client connected");
    }
    else
    {
     ret=recv(fd,buff,100,0);
     if(ret<0) 
     {
      perror("recv");
      FD_CLR(fd,&rfds);close(fd);cnt--;
      if(fd==maxfd) {maxfd--;}
     }
     else if(ret==0)//no activity
     {
      printf("client on socket fd %d is disconnected,removing client\n",fd);
      FD_CLR(fd,&rfds);close(fd);cnt--;
      if(fd==maxfd) maxfd--;
     }
     else
     {
      printf("receved from client:\n");
      printf("msg:%s\n",buff);
      if(send(fd,buff,100,0)<0)
      {perror("send");close(fd);}
      printf("server echoed:%s\n",buff);
      if(strcmp(buff,"quit")==0)
      {
       puts("formally closing connection");
       printf("removing client on socket fd %d \n",fd);
       FD_CLR(fd,&rfds);close(fd);cnt--;
       if(fd==maxfd) {maxfd--;}
      }  
     }//else //if ret is valid
    }//else
   }//if(FD_TSSET(fd,&testfd))
  }//for loop 
 }//while(1)

//end
 close(sfd);
 return 0;
}
 
 void client_info(struct sockaddr_in caddr)
{
 printf("client whose ephemeral port is %d and it's ipv4 address is %s",ntohs(caddr.sin_port),inet_ntoa(caddr.sin_addr));
}

