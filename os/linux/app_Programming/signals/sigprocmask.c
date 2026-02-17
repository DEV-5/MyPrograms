#include <signal.h>
#include <stdio.h>

int main (){
    sigset_t s_set;
    sigemptyset(&s_set);
    sigaddset(&s_set, 62);
    sigaddset(&s_set, 4);
    sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
    getchar();
}
