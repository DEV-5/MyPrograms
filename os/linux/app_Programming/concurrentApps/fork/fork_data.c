#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD	0

int main(){
	int commonVar = 10;
	pid_t cpid = fork();
	if (cpid == CHILD){
		printf("Executing Child and pid=%d ...\r\n", getpid());
		printf("child: value of commonVar = %d and addr=%x\r\n", commonVar, &commonVar);
		commonVar = 20;
		printf("child: value of commonVar = %d and addr=%x\r\n", commonVar, &commonVar);

		getchar();
		printf("child: value of commonVar = %d and addr=%x\r\n", commonVar, &commonVar);
		printf("Exiting Child ...\r\n");
		exit(6);
    	}
	else{
		int childstatus;
		printf("Executing Parent and pid=%d ...\r\n", getpid());
		printf("parent: value of commonVar = %d and addr=%x\r\n", commonVar, &commonVar);
		// commonVar = 31;
		// printf("parent: value of commonVar = %d and addr=%x\r\n", commonVar, &commonVar);

		pid_t retPid = wait(&childstatus);

		if (retPid == -1)
			perror("wait failed!!!\n");
		if (WIFEXITED(childstatus))
			printf("inside parent: after wait child pid=%d exited status gathered:%d\r\n", retPid, WEXITSTATUS(childstatus));
		if (WIFSIGNALED(childstatus))
			printf("%s signal caused termination\r\n",strsignal(WTERMSIG(childstatus)));
		
		printf("parent: value of commonVar = %d and addr=%x\r\n", commonVar, &commonVar);
		// while(1);
		printf("Exiting parent\n");
	}
}
