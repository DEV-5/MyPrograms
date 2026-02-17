// -lrt (lib rt needs to be included)
#include <time.h>

int main(){
        struct itimerspec ts;
        timer_t tid;

        timer_create(CLOCK_MONOTONIC, NULL, &tid);

        ts.it_value.tv_sec = 1;
        ts.it_value.tv_nsec = 0;
        ts.it_interval.tv_sec = 1; // periodic interval (0 for oneshot)
        ts.it_interval.tv_nsec = 0;

        timer_settime(tid, 0, &ts, NULL);
}
