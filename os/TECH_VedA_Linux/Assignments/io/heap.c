#include <stdio.h>
#include <unistd.h>

int main(void){
    void *curr_brk, *def_brk, *new_brk;
    /* Grab current program break address */
    curr_brk = sbrk(0);
    def_brk  = curr_brk;
    printf("\ncurrent_brk= %p \n", curr_brk);
    getchar();
    /* Change the location the program break using brk(allocate 100 bytes of heap) */
    brk(curr_brk + 100);
    /* verify change */
    new_brk = sbrk(0);
    printf("new_brk= %p\n",new_brk);
    /* Restore default location of the program break */
    brk(def_brk);
}
