#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void handler (int signum){
		static unsigned int sigcounter;
		printf("%s: handler involved counter set to %d \n", __func__, ++sigcounter);
		//getchar();
		printf("%s: exiting handler\n", __func__);
}

int main(){
	struct sigaction act;
	sigset_t sigmask;

	memset(&act, 0, sizeof(act));
	sigemptyset(&sigmask);
	sigaddset(&sigmask, SIGINT);
	sigaddset(&sigmask, SIGTERM);
	/* Install signal handler */
	act.sa_handler = handler;
	act.sa_mask    = sigmask;
	sigaction(SIGQUIT, &act, NULL);
	// sleep(5);
	printf("%s: before getchar()\n", __func__);
	getchar();
	printf("%s: after getchar()\n", __func__);
	while(1);
	printf("%s: after while(1)\n", __func__);
}
