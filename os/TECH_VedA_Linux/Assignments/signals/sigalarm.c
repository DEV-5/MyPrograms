#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
    sigset_t waitset;
    siginfo_t info;
    /* Let's disable async handlers and enable signal queue */
    sigemptyset(&waitset);
    sigaddset(&waitset, SIGALRM);
    sigprocmask(SIG_BLOCK, &waitset, NULL);
    alarm(5);
    // timestamp("before sigwaitinfo()");
    /* Wait for alarm to arrive
     * Step 1: Block until specified signals arrive into pending list 
     * Step 2: When any signal mentioned in the set occurs, return with all meta-data describing signal's occurrence
     */
    int results = sigwaitinfo(&waitset, &info);
    if (results < 0)
        printf("signal wait info failed !!!\n");
    /* got the alarm */
    printf("sigwaitinfo() returned from signal %d  \n", results);   
}
