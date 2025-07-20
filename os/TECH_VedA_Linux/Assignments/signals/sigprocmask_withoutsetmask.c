#include <stdio.h>
#include <signal.h>

int main(){
    sigset_t s_set;
    sigaddset(&s_set, 2);
    sigprocmask(SIG_BLOCK, &s_set, NULL);
    sigemptyset(&s_set);
    sigaddset(&s_set, 4);
    sigprocmask(SIG_BLOCK | SIG_SETMASK, &s_set, NULL);
    getchar();
}
