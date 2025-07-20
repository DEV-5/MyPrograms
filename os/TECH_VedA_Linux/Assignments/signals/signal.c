#include <stdio.h>
#include <signal.h>

void handler (int signum){
	static unsigned int sigcounter;
	printf("%s: handler involved counter set to %d \n", __func__, ++sigcounter);
}

int main(){
        printf("app start\n");
    	signal(SIGINT, handler); /* set user handler for signal 2 */
    	// signal(SIGINT, SIG_DFL); /* set default kernel handler for signal 2 */
	printf("configured handler for SIGINT (ctr + c)\n");
	getchar();
	return 0;
}
