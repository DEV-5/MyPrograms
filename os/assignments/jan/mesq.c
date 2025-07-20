
//DATE:25-1-17
typedef struct 
{
 long mtype;
 char mtext[20];
}msgbuf;

#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
 int mqid;
 msgbuf buf;
 mqid= msgget(1,IPC_CREAT|0666);
 if(mqid==-1){perror("msgget");return 0;}
 if(msgrcv(mqid,&buf,20,buf.mtype,0)==-1){perror("msgrcv");exit(1);}
 printf("%d:%s\n",getpid(),buf.mtext);
}
