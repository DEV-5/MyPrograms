//Author: Vasudev.m
//Date: 2-12-19   
//purpose: Implementing conditional variable api that uses Reader-Writer Lock

#include<stdio.h>
#include<semaphore.h>
#include<sys/unistd.h>
#include<time.h>
#include<linux/futex.h>

#define WAKE_ONE 0
#define WAKE_ALL 1

typedef struct {
sem_t sema;
int No_of_updates;
                }Lock_t;
/*
static int futex(int *vaddr, int futex_op,int val, 
        const struct timespec *timeout,int * vaddr2,int val3)
{
    return syscall(SYS_futex,vaddr,futex_op,val,timeout,vaddr2,val3);
}
*/
int CVRW_Read_Lock(Lock_t lck)
{
    return lck.No_of_updates; 
}

int CVRW_Write_Lock(Lock_t lck)
{
    return lck.No_of_updates; 
}
