//Date: 10-11-19
#include <stdio.h>
#include <signal.h>
#include <unistd.h> 
#include <stdlib.h>
/*signal handler for SIGINT*/
void signal2_handler(int signum)
{
    printf("Signal %d has been delivered \n",signum);
    sleep(100);
    printf("End of signal %d handling\n",signum);
}   
/*signal handler for SIGQUIT*/
void signal3_handler(int signum)
{
    printf("Signal %d has been delivered \n",signum);
    sleep(4);
    printf("End of signal %d handling\n",signum);
}


int main()
{
    struct sigaction sa;
    memset(&sa,0,sizeof(sa)); //setting all bytes of struct to zero
    sigset_t sigmask;

    printf("Inside signal_main pid = %d\n",getpid());
    //using signal api to handle signals 
    signal(SIGINT,signal2_handler);
    //using sigaction api to handle signals
    sa.sa_handler = signal3_handler;
    sa.sa_flags = SA_NODEFER;//signal of same type will be able to interrupt handler execution
    sigaction(SIGQUIT,&sa,NULL);

    //signal(SIGQUIT,signal3_handler);
    //sigemptyset(&sa);
    //sigaddset(&sigmask,SIGQUIT);
    //sa.sa_mask = sigmask;
    getchar();
    return 0;
}
