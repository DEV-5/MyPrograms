#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD	0
void handler(int signum)
{
	int status;
	printf("start of signal handler\n");
	wait(&status);
	printf("Exiting signal handler exit status=%d\n", WEXITSTATUS(status));
}

void atExitChild(){
	printf("Exiting Child ...\r\n");
}

int main(){
	int ret;
	pid_t cpid = fork();
	if (cpid == CHILD){
	printf("Executing Child and pid=%d ...\r\n", getpid());
	ret = atexit(atExitChild);
	exit(55);
	}
	else{
		if (signal(SIGCHLD, handler) == SIG_ERR)
		{
			perror("signal failed\n");
		}
		printf("Signal SIGCHLD handler is setup\r\n");

		getchar();
		printf("Exiting parent\n");
	}
}
