#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD	0

int main(){
	pid_t cpid = fork();
	if (cpid == CHILD){
		printf("Executing Child and pid=%d ...\r\n", getpid());
		getchar();
		printf("Exiting Child ...\r\n");
		exit(6);
    	}
	else{
		int childstatus;
		printf("Executing Parent and pid=%d ...\r\n", getpid());
		pid_t retPid = wait(&childstatus);

		if (retPid == -1)
			perror("wait failed!!!\n");
		if (WIFEXITED(childstatus))
			printf("inside parent: after wait child pid=%d exited status gathered:%d\r\n", retPid, WEXITSTATUS(childstatus));
		if (WIFSIGNALED(childstatus))
			printf("%s signal caused termination\r\n", strsignal(WTERMSIG(childstatus)));
		while(1);
		printf("Exiting parent\n");
	}
}
