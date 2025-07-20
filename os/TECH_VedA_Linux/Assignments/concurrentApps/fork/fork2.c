#include <stdio.h>
#include <unistd.h>

#define CHILD	0

int main(){
    pid_t childpid = fork();
    
    if (childpid == 0)
    {
        /* CHILD EXECLUSIVE CODE */
        printf("Child pid:%d\r\n", getpid());
    }
    else
    {
        /* PARENT EXECLUSIVE CODE */
        printf("Parent pid:%d\r\n", getpid());
    }
    /* PARENT AND CHILD MUTUAL CODE */
    printf("This will print twice\n");
}
