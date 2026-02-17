#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void handler (int signum)
{
	static unsigned int sigcounter;
	printf("%s: handler involved counter set to %d \n", __func__, ++sigcounter);
}

int main(){
	struct sigaction act;
	//memset(&act, 0, sizeof(act)); /* Install signal handlers */
	act.sa_handler = handler;
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGINT);
	sigaction(SIGINT, &act, NULL);  /* providing null as previous handler info is not fetched */
	// printf("flags:%d and SA_RESETHAND:%d\r\n", act.sa_flags, SA_RESETHAND);
	printf("before getchar()\r\n");
	getchar();
	printf("after getchar()\r\n");
	// sleep(7);
	// while(1);
}
