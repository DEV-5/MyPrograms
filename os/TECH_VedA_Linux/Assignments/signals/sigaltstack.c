#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler (int signum){
		static unsigned int sigcounter;
		printf("%s: handler involved counter set to %d \n", __func__, ++sigcounter);
}

int main(){
	stack_t sigstack;
	sigstack.ss_sp = malloc(SIGSTKSZ);
	if(sigstack.ss_sp == NULL){
		perror("malloc \n");
    		exit(EXIT_FAILURE);
	}
	sigstack.ss_size = SIGSTKSZ;
	sigstack.ss_flags = 0;

	if(sigaltstack(&sigstack, NULL) == -1){
    		perror("sigstack \n");
    		exit(EXIT_FAILURE);
	}
 	
	struct sigaction sa;
	sa.sa_flags = SA_ONSTACK;
	sa.sa_handler = handler;      /* Address of a signal handler */
   	sigemptyset(&sa.sa_mask);
    	if (sigaction(SIGINT, &sa, NULL) == -1) {
  		perror("sigaction");
        	exit(EXIT_FAILURE);
    	}
	getchar();
}
