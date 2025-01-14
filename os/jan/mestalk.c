
//DATE: 24-1-17
typedef struct 
{
 long mtype;
 char mtext[100];
}msgbuf;

#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
 int mqid=msgget((key_t)1,0);
 msgbuf buf;
 //gets(buf.mtext);
 scanf("%s",buf.mtext);
 printf("|%s|(len:%d)\n",&buf.mtext,strlen(buf.mtext));
 buf.mtype=1; 
 if(msgsnd(mqid,&buf,strlen(buf.mtext)+1,0)==-1)
 {perror("msgsnd");return 0;}
 msgctl(mqid,IPC_RMID,0);
}
