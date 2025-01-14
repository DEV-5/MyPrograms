
//DATE:26-2-17
#include"myhead.h" 
int main(int argc,char** argv)
{
 if(argc<3)
 {puts("input format: client.exe  well_known_portofserver ipofserver");
 return 0;
 }	
 int fd;
 puts("creating a server connection"); 
 fd = socket(AF_INET,SOCK_STREAM,0);//SOCK_STREAM is for tcp
 if(fd<0){perror("socket");return 0;}
 puts("client socket created");
 puts("binding&connecting");
 struct sockaddr_in addr;
 addr.sin_family = AF_INET;
 addr.sin_port = htons(atoi(argv[1]));
 addr.sin_addr.s_addr = inet_addr(argv[2]);
 if(connect(fd,(const struct sockaddr*)&addr,sizeof(addr))<0)
 {perror("connect");close(fd);return 0;}
 puts("bind success");
 char buff[100];int status;
  puts("enter a message for the server: ");
  scanf("%s",buff);
 //gets(buff);
  status=send(fd,buff,100,0);
  if(status<0)
  {perror("send");}
  printf("sent: %s\n",buff);
  //if(strcmp(buff,"bye")==0)  
  close(fd);
}

/*
 puts("waiting to accept connection from any client");
 struct sockaddr_in caddr; int clen = sizeof(caddr);
 int cfd;
 cfd = accept(sfd,(struct sockaddr*)&caddr,&clen);
 if(cfd==0) {perror("accept");close(sfd);return 0; }
 puts("connection success");
 puts("connection with client");
 unsigned short portno;
 char *ip;
 portno = ntohs(caddr.sin_port);
 ip = inet_ntoa(caddr.sin_addr);// issue 
 printf("whose ip is %s &port is %d \n",ip,portno);
 char buff[100];int status;
 puts("waiting for message from the client...");
 status = recv(cfd,buff,100,0);
 if(status<0)
 { perror("recv");}
 else if(status ==0)
  puts("client abnormally terminated");
  else
 { 
  printf("server recv:%s \n",buff);
   if((strcmp(buff,"bye")==0)||(strcmp(buff,"BYE")==0))
  puts("client formally exited");	
 }
 close(cfd);
 close(fd);
 return 0;
}*/
