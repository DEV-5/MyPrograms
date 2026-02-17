#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t childpid;
    childpid  = fork();
    printf("%s hello fork %d\n", __func__, getpid());
}
