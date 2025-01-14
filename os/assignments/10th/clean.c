
//DATE:6-1-17
#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

void isr (int n)
{
 exit(0);
}

 int main()
{
 int id,n=0;
 char *ptr;
 id = shmget(2,1000,IPC_CREAT|0600);
 if(id==-1){perror("shmget_ser");exit(0);}
 ptr=shmat(id,NULL,0);
 if(ptr==NULL){perror("shmat_ser");exit(0);}
 //printf("the shared memory segment has<%p:%s>\n",&ptr,ptr);
 printf("sms (%p)had<%s>\n",&ptr,ptr);
 //strcpy(ptr,"this is sparta\n");
 
 while(n<1000){*(ptr+n)='\n';n++;}
 printf("sms (%p)has<%s>\n",&ptr,ptr);
 /*  if(fork())
 {
  while(1)
  {
   while(*ptr) ptr++;
   printf("%s",name);
   do
    {
     buf=realloc(buf,n+1);
     buf[n++]=getchar();
    }while((*buf)!='\n');
   strcpy(ptr,name);
   ptr+=6;
   strcpy(ptr,buf);
   free(buf);
   buf=0;
  }
 }

 else
 {
  do{ printf("in printer\n");}while(0);
  while(1)
  {
   if(*ptr)
   {
    n=printf("user:%s",ptr);
    ptr+=n;
   }
  }
 }*/
 return 0;
}

