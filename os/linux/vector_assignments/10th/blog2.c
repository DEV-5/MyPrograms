
//vasudev.m
//DATE:7-3-17
#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<pthread.h>

void* write_th(void *p);
void* read_th(void *p);

pthread_t t1,t2;
char *ptr,*buf=0,name[]="\nVASU:";
int id,n=6;

void isr (int n)
{
 exit(0);
}

 int main()
{
 struct sigaction st;
 id = shmget(3,1000,IPC_CREAT|0660);
 if(id==-1){perror("shmget_ser");exit(0);}
 ptr=shmat(id,NULL,0);
 if(ptr==NULL){perror("shmat_ser");exit(0);}
 printf("the shared memory segment has<%p:%s>\n",&ptr,ptr);
 st.sa_handler = isr;
 sigaction(SIGCHLD,&st,NULL);
 pthread_create(&t1,NULL,write_th,NULL);
 pthread_create(&t2,NULL,read_th,NULL);
 pthread_exit(0);
}

  void* write_th(void *p)
 {
   while(1)
  {
   while(*ptr) ptr++;
   printf("%s",name);
   buf=realloc(buf,n+1);
   strcpy(buf,"VASU: ");
   do
    {
     buf = realloc(buf,n+1);
     buf[n++]=getchar();
    }while((buf[n-1])!='\n');  
   printf("you have entered: %s\n",buf);
   //strcpy(ptr,"Dev:");
   //ptr+=4;
   strcpy(ptr,buf);
   ptr+=strlen(buf);
   free(buf);
   buf=0;
   n=5;
  }
 }

 void* read_th(void *p)
 {
  //do{ printf("in printer\n");}while(0);
  while(1)
  {
   if(*ptr)
   {
    while(*ptr)
    {
     putchar(*ptr);
     ptr++;
    }
  /*n=printf("%s",ptr);
    ptr+=n;
    n=0;*/
   }
  }
 }

