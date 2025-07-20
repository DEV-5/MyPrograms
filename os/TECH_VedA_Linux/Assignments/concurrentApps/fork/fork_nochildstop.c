#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD	0

void sighand(int signum)
{
	int status;
	printf("start of signal handler of process pid:%d for signal %d: %s\n", getpid(), signum, strsignal(signum));
	wait(&status);
	printf("Exiting signal handler %d\n", WEXITSTATUS(status));
}

int main(){
	struct sigaction act;
	pid_t cpid = fork();
   	if (cpid == CHILD){
		printf("Executing Child and pid=%d ...\r\n", getpid());
		getchar();
		printf("Exiting Child ...\r\n");
		while(1);
		exit(6);
    }
	else{
		int childstatus;
        	/* Disable other state change notifications (SIGSTOP, SIGCONT) */
        	act.sa_flags = SA_NOCLDSTOP;
        	act.sa_handler = sighand;
        
		if (sigaction(SIGCHLD, &act, NULL) == -1)
			perror("signal failed\n");
		printf("Executing Parent and pid=%d ...\r\n", getpid());
		pid_t retPid = wait(&childstatus);
		printf("Exiting parent\n");
    }
}
