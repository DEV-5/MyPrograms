
//DATE:11-1-17
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
pthread_t t1,t2;
sem_t s1,s2;

 void* thread1(void* ptr)
{
 int i='A',s1_val,s2_val;
// printf("in thread1 my pid is=%d \n",getpid());
 
 while(i<('A'+26))
 { 
  sem_wait(&s1);
  printf("%c",i);
 // sem_getvalue(&s1,&s1_val);
 // sem_getvalue(&s2,&s2_val);
 // printf("%c(s1=%d and s2=%d) \n",i,s1_val,s2_val);
 if(i>'A') sem_post(&s2);
 i++;
 }
}
 void* thread2(void* ptr)
{
 int a,i='a',s1_val,s2_val;
// printf("in thread2 my pid is=%d \n",getpid());
 while(i<('a'+26))
 {
  sem_wait(&s2);
 // printf("|%d|",a);
 // sem_getvalue(&s1,&s1_val);
 // sem_getvalue(&s2,&s2_val);
 // printf("%c(s1=%d and s2=%d) \n",i++,s1_val,s2_val);
  printf("%c ",i++);
  sem_post(&s1);
 }
 puts("");
}


 int main()
{
 printf("in main my pid is=%d \n",getpid());
 sem_init(&s1,0,1);
 sem_init(&s2,0,1);
 pthread_create(&t1,NULL,thread1,NULL);
 pthread_create(&t2,NULL,thread2,NULL);
 pthread_exit(0);
}

