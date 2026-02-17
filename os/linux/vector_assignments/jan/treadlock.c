
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_t th1,th2;
int n1,n2;
pthread_mutex_t m1,m2;

void* thread_1(void* p)
{
// while(1)
{	
 pthread_mutex_lock(&m1);
 printf("you are in thread1\nplease enter  2 numbers: ");
 scanf("%d %d",&n1,&n2);
 printf("the sum of the given numbers is %d\n",n1+n2);
 while(m2);
 pthread_mutex_unlock(&m1);
 //pthread_mutex_lock(&m2);
// pthread_mutex_unlock(&m2);
// while(pthread_mutex_unlock(&m2)==-1);
 }
}
void* thread_2(void* p)
{
//while(1)
{
pthread_mutex_lock(&m2);
//printf("the value of m1:%d and m2:%d\n",m1,m2);
//printf("valueofm1:%d:\n",pthread_mutex_unlock(&m1));
//printf("valueofm2:%d:\n",pthread_mutex_lock(&m1));
printf("you are in thread2\nplease enter two numbers: ");
scanf("%d %d",&n1,&n2);
printf("the product of the given numbers is %d\n",n1*n2);
while(m1);
pthread_mutex_unlock(&m2);
}
}


int main()
{
pthread_mutex_init(&m1,0);
pthread_mutex_init(&m2,0);
pthread_create(&th1,NULL,thread_1,NULL);
pthread_create(&th2,NULL,thread_2,NULL); 
pthread_exit(0);
}
