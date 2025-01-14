/asd/muti threading app with non-atomic instructions
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>

int G_var;

void* Thread_function(void * ARG)
{
    for(int a = 0;a<1000;a++)
    {
        G_var++; //non atomic instruction will lead to uncertainity
        //__sync_fetch_and_add(&G_var,1); //gnu atomic op macro
        
    }
    pthread_exit(0);
}

int main()  
{
    int a;
    pthread_t th1,th2;      
    printf("Start of Application \n");
    for(int j = 0; 1 ;j++) // infinite loop
    {
        pthread_create(&th1,NULL,Thread_function,NULL);
        pthread_create(&th2,NULL,Thread_function,NULL);
        pthread_join(th1,NULL);
        pthread_join(th2,NULL);
        //printf("The Value of G_var = %d \n",G_var);
        if(G_var != 2000)
        {
            printf("Itteration %d the Value of G_var = %d \n",j,G_var);
            exit(1);
        }
        G_var = 0;
    }
    return 0;
}
