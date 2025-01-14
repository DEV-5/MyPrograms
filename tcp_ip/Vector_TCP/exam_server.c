
#include"myhead.h"

char* change(char* buf);

 int main(int argc,char** argv)
{
 if(argc<2){puts("cla format: ./ex_s port");return 0;}
 int sfd;
 sfd=socket(AF_INET,SOCK_STREAM,0);
 if(sfd<0){perror("socket");return 0;}
 struct sockaddr_in saddr;
 int size=sizeof(struct sockaddr);
 saddr.sin_family= AF_INET;
 saddr.sin_port= htons(atoi(argv[1]));
 saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
 if(bind(sfd,(struct sockaddr*)&saddr,size)<0)
 {perror("bind");return 0;}
 if(listen(sfd,1)<0)
 {perror("listen");return 0;}
 int cfd;
 struct sockaddr_in caddr;
  cfd=accept(sfd,(struct sockaddr*)&caddr,&size);
  if(cfd<0){perror("accept");return 0;}
 int r,s;
 char buf[100],*res;
  r=recv(cfd,buf,100,0);
  if(r<0){perror("recv");}
  else if(r==0){printf("the client exited abruptly");exit(0);}
  printf("client sent:%s",buf);
  res=change(buf);
  s=send(cfd,res,100,0);
  if(s<0){perror("send");}
  else if(s==0){printf("the client exited abruptly");}
  close(cfd);
  close(sfd);
  return 0;
}

char* change(char* buf)
{
 static char arr[29]="one twenty ",wrong[30]="you have entered a wrong digit";
 if(strstr(buf,"12"))
 switch(buf[2])
 {
 case '1': if(~strcmp(buf,"121")){strcat(arr,"one");break;}else return wrong;
 case '2': if(~strcmp(buf,"122")){strcat(arr,"two");break;}else return wrong;
 case '3': if(~strcmp(buf,"123")){strcat(arr,"three");break;}else return wrong;
 case '4': if(~strcmp(buf,"124")){strcat(arr,"four");break;}else return wrong;
 case '5': if(~strcmp(buf,"125")){strcat(arr,"five");break;}else return wrong;
 case '6': if(~strcmp(buf,"126")){strcat(arr,"six");break;}else return wrong;
 case '7': if(~strcmp(buf,"127")){strcat(arr,"seven");break;}else return wrong;
 case '8': if(~strcmp(buf,"128")){strcat(arr,"eight");break;}else return wrong;
 case '9': if(~strcmp(buf,"129")){strcat(arr,"nine");break;}else return wrong;
 default :return wrong; 
/* case '2': strcat(buf,"two");break;
 case '3': strcat(buf,"three");break;
 case '4': strcat(buf,"four");break;
 case '5': strcat(buf,"five");break;
 case '6': strcat(buf,"six");break;
 case '7': strcat(buf,"seven");break;
 case '8': strcat(buf,"eight");break;
 case '9': strcat(buf,"nine");break*/

 }
 return arr;
}
