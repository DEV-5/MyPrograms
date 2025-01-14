
//DATE:11-1-17
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

pthread_t t1,t2;
sem_t s1,s2;

 void* thread1(void* ptr)
{
 int i='A';
// printf("in thread1 my pid is=%d \n",getpid());
  while(i<('A'+26))
 { 
  sem_wait(&s1);
  printf("%c\n",i++);
  sem_wait(&s1);
  sem_post(&s2);
//  sem_post(&s1);
 }
}
 void* thread2(void* ptr)
{
 int a,i='a';
// printf("in thread2 my pid is=%d \n",getpid());
 while(i<('a'+26))
 {
  sem_post(&s1);
  sem_wait(&s2);
 // printf("|%d|",a);
  printf("%c\n",i++);
  sem_wait(&s2);
 // sem_post(&s2);
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

