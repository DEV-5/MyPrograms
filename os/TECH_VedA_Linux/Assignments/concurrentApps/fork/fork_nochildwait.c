#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD	0

int main(){
	struct sigaction act;
	pid_t cpid = fork();
   	if (cpid == CHILD){
		printf("Executing Child and pid=%d ...\r\n", getpid());
		getchar();
		printf("Exiting Child ...\r\n");
		///while(1);
		exit(6);
    }
	else{
		int childstatus;
        	/* Disable other state change notifications (SIGSTOP, SIGCONT) */
        	act.sa_flags = SA_NOCLDWAIT;
        	act.sa_handler = SIG_DFL;
        
		if (sigaction(SIGCHLD, &act, NULL) == -1)
			perror("signal failed\n");
		printf("Executing Parent and pid=%d ...\r\n", getpid());
		while(1);
		/* check ps for zombified child, it shoulkd not be present as it is reaped by default SA_NOCLDWAIT handler */
		printf("Exiting parent\n");
    }
}
