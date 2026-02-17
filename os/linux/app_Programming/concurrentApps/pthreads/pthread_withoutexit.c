#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

static void *threadFunction(void *arg){
	char *s = (char *)arg;
	printf("%s: argstring: %s\r\n", __func__, s);
	getchar();
	printf("%s:End of sub thread\r\n", __func__);
	return (void *) strlen(s);
}

int main(){
	pthread_t t1;
	void *res;
	int ret;

	printf("creating a thread\r\n");
	ret = pthread_create(&t1, NULL, threadFunction, "Hello World");
	if (ret != 0)
	{
		perror("pthread_create error!!!\r\n");
		exit(EXIT_FAILURE);
	}
	printf("%s: Thread return\r\n", __func__);
	//sleep(1);
	void * retval;
	pthread_exit(retval);
}
