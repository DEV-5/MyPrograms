
//DATE:25-2-17
#include"myhead.h" 
//#include<sys_socket.h> 
int main(int argc,char** argv)
{
 if(argc<2)
 {puts("input format: server.exe  well_known_port");return 0;}	
 int sfd;
 puts("creating a server connection"); 
 sfd = socket(AF_INET,SOCK_STREAM,0);//SOCK_STREAM is for tcp
 if(sfd<0){perror("socket");return 0;}
 //perror("test");
 puts("server socket created");
 puts("binding");
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
 puts("waiting to accept connection from any client");
 struct sockaddr_in caddr; int clen = sizeof(caddr); int cfd=1;
 
 
 

 cfd = accept(sfd,(struct sockaddr *)&caddr, &clen);
 if(cfd<0) {perror("accept");close(sfd);return 0; }
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
 close(sfd);
 return 0;
}

