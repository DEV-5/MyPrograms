#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
//#include "libtest.h"

int main (void)
{
    void * handle;
    
    /* STEP1: Declare a function pointer */
    void (*fnptr1) (void);
    void (*fnptr2) (void);
    printf("<<%s: start of main>>\n",__func__);
    
    /* STEP2: Request link loader to load specific library and attach it to the address space */
    handle = dlopen("./libdrv.so", RTLD_NOW);
    if (handle == NULL)
    {
        printf("Failed to load library libdrv.so\n");
        exit(2);
    }
    
    /* STEP3: lookup for the address of the required function */
    dlerror(); // clear all dl error 
    fnptr1 = dlsym(handle, "x");
    
    if (dlerror() != NULL)
    {
	printf("Unable to load function x from libtest.so\n");
        exit(2);
    }
    
    fnptr2 = dlsym(handle, "y");
    
    if (dlerror() != NULL)
    {
	printf("Unable to load function y from libtest.so\n");
        exit(2);
    }
    /* STEP4: Invoke the function trough the pointer */
    (fnptr1)();
    (fnptr2)();

    
    /* STEP5: Request link loader to unlink specific library from the address space */
    dlclose(handle);
}
