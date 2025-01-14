#include<stdio.h>
#include<unistd.h>
//#include<sleep.h>
int main()
{
    printf("\n\nMESSAGE : hello world  ");
    fflush(stdout);
    sleep(3);
    //printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
    //printf("[14]\b");
    printf("\vbye world  \n");
}
