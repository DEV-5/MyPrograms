
//DATE: 22-12-16
#include<stdio.h>
#include<stdlib.h>
//#include<signal.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

//char ex[3];
char ex[3]="";

 void waiter(int n)
{
 int v=0,pid=0;
 double t; 
 pid = wait(&v);
 t=clock();
 t/=1000000;
 v>>=8;
 if(v!=0)printf("pid:%d child %d has exited time elapsed:%.3f \n",pid,v,t);
 ex[v-1]=1;
 //if(ex[0]&&ex[1]&&ex[2])kill(getpid(),SIGKILL);
 if(ex[0]&&ex[1]&&ex[2])exit(0);
}

 void alm(int n)
{
 static int count;
 double t;
 printf("alarm %d....\n",count+1);
 if(ex[count]==0)
 {
  t=clock();
  t/=1000000;
  printf("killing child: %d,pid:%d,time elapsed:%.3f\n",count+1,getpid()+count+1,t); 
  kill(getpid()+count+1,SIGKILL);
  ex[count]=1;
 }
 else printf("\nchild %d is already dead\n",count+1);
  
 count++;
 alarm(3-count);
 //if(ex[0]&&ex[1]&&ex[2])kill(getpid(),SIGKILL);
 if(ex[0]&&ex[1]&&ex[2])exit(0);
//  if(count==3)kill(getpid(),SIGKILL);
}	

 int main()
{
 int delay;

 if(fork()==0)
 {
  srand(getpid());
  delay=1+rand()%10;
  printf(" In child 1:%d with delay:%d and it's parent is :%d \n",getpid(),delay,getppid());
  sleep(delay);
  exit(1);
 }
 else if(fork()==0)
 {
  srand(getpid());
  delay=1+rand()%10;
  printf(" In child 2:%d with delay:%d and it's parent is :%d \n",getpid(),delay,getppid());
  sleep(delay);
  exit(2);
 }
 else if(fork()==0)
 {
  srand(getpid());
  delay=1+rand()%10;
  printf(" In child 3:%d with delay:%d and it's parent is :%d \n",getpid(),delay,getppid());
  sleep(delay);
  exit(3);
 }
 else
 {
  struct sigaction t;

  srand(getpid());
  //signal(SIGCHLD,waiter);
  t.sa_handler=waiter;
  sigaction(SIGCHLD,&t,NULL);
  t.sa_handler=alm;
  sigaction(SIGALRM,&t,NULL);
  //signal(SIGALRM,alm);
  printf(" In watchdog :%d and it's parent is :%d \n",getpid(),getppid());
  alarm(4);
  while(1);
 //while(wait(NULL)==-1);
  exit(0);
 }
}
