
//DATE:6-1-17
#include<stdio.h>
#include<sys/shm.h>
//#include<sys/types.h>
#include<stdlib.h>

 int main()
{
 int id;
 char* ptr;
 id = shmget(1,20,IPC_CREAT|0600);
 if(id==-1){perror("shmget");exit(0);}
 ptr=shmat(id,NULL,0);
 if(ptr==NULL){perror("shmat");exit(0);}
 printf("the shared memory segment has<%s>\n",&ptr);
 return 0;
}
