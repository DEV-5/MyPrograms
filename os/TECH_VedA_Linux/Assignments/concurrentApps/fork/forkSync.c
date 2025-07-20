#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD	0

int main(){
    int status;
    pid_t cpid = fork();
    
    if (cpid == CHILD){
        printf("Executing Child and pid=%d ...\r\n", getpid());
		getchar();
        printf("Exiting Child ...\r\n");
        exit(12);
    }
	else{
        pid_t retPid = wait(&status);
        if(retPid == -1)
        {
            perror("wait failed\n");
        }
        printf("inside parent: after wait child pid=%d exited with status %d\r\n", retPid, WEXITSTATUS(status));
        printf("Exiting parent\n");
    }
}
