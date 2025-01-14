
//DATE:6-1-17
#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>

 int main()
{
 int id,n;
 char *ptr,ch;
 id = shmget(1,20,IPC_CREAT|0600);
 if(id==-1){perror("shmget_ser");exit(0);}
 ptr=shmat(id,NULL,0);
 if(ptr==NULL){perror("shmat_ser");exit(0);}
 printf("the shared memory segment has<%p:%s>\n",&ptr,ptr);
  
  if(fork())
 {
   while(*ptr) ptr++;
   while((ch=getchar())!='\n')
  {
   *ptr=ch;
   ptr++;
  }
 }
 else
  while(1)
  {
   if(*ptr)
   {
    n=printf("%s",ptr);
    ptr+=n;
   }
  }
 return 0;
}
