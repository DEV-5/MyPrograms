
//DATE: 8-1-17
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
//#include<

pthread_mutex_t M,N;

void* thread1(void* res)
{
 char ch='a';
// sleep(1);
 while(ch!=('a'+26))
 { 
 // pthread_mutex_unlock(&N);
  pthread_mutex_lock(&M);
  printf("%c ",ch++); 
//  pthread_mutex_unlock(&M);
  pthread_mutex_unlock(&N);
 }
}
void* thread2(void* res)
{
 char ch='A';
  while(ch!=('A'+26))
 {
 // pthread_mutex_unlock(&N);
  pthread_mutex_lock(&N);
 //pthread_mutex_lock(&M);
  printf("%c",ch++); 
  pthread_mutex_unlock(&M);
 // pthread_mutex_unlock(&M);
 }
}

int main()
{
 pthread_t td1,td2;
 printf("inside main 	\n");
 pthread_mutex_init(&M,0);
 pthread_mutex_init(&N,0);
// pthread_mutex_lock(&M);
// pthread_mutex_lock(&N);
 printf("\n before thread creation\n");
 pthread_create(&td2,NULL,thread2,NULL);
 pthread_create(&td1,NULL,thread1,NULL);
// pthread_mutex_unlock(&M);
// pthread_mutex_unlock(&N);
 pthread_exit(0);
}
