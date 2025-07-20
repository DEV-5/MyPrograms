#include <stdio.h>
#include <signal.h>

int main(){
	sigset_t s;
	//sigaddset(&s_set, SIGINT);
    	sigprocmask(SIG_BLOCK, NULL, &s);
    	int res = sigismember(&s, SIGINT);
	int i = SIGINT;
    	if (res)
        	printf("Signal %d is blocked \n",i);
	else
        	printf("Signal %d is not blocked \n", i);
	getchar();
    	sigemptyset(&s);
	sigaddset(&s, SIGINT);
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s, NULL);
    	
	sigemptyset(&s);
	sigprocmask(SIG_BLOCK, NULL, &s);
    	res = sigismember(&s, SIGINT);
    	if (res)
        	printf("Signal %d is blocked \n",i);
	else
        	printf("Signal %d is not blocked\n", i);
	getchar();
}
