#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define DEATH(mess) { perror(mess); exit(errno); }

static void *threadFunction(void *arg){
	char *s = (char *)arg;
	printf("%s: argstring: %s\r\n", __func__, s);
	getchar();
	return (void *) strlen(s);
}

int main(){
	pthread_t thr;
	pthread_attr_t attr;
	int ret;

	printf("creating a thread\r\n");
	ret = pthread_attr_init(&attr);
	if (ret != 0)
		perror("pthread_attr_init error !!!\r\n");
	/* Assign detached state to PTHREAD_CREATE_DETACHED */
	ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if (ret != 0)
		perror("pthread_attr_setdetachstate error !!!\r\n");

	ret = pthread_create(&thr, NULL, threadFunction, "Hello World");
	if (ret != 0)
		DEATH("pthread_create error!!!\r\n");
	pthread_exit(NULL);
}
