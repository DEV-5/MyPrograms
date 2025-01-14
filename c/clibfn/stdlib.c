/*
 *NAME: Vasudev M
 *DATE: 13th March 2020
 *Description: Example for function in stdlib library
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void function()
{
    printf("Inside the function which is executing before exit\n");
}

int values[] = { 88, 56, 100, 2, 25 };

int main()
{
    double dbl,dbl2,dbl3;
    int i,*iptr,n;
    void *vptr;
    long int li;
    int res_help;
    int res_zero;
    int rand_num;
    int *item;
    int key = 2;
    char *end;


    i = atoi("12.5");//value till . is condidered
    dbl = atoi("12.5");
    dbl2 = atof("12.5");
    dbl3 = atof("12.5A3");//string still a is considered
    li = atol("3902999992A1");//string value untill a is considered
    vptr = malloc(8);//allocating 8 bytes for memory the buffer is not zeroized
    iptr = (int *) calloc(2,sizeof(int));//allocating a buffer of int & the buff is zero intialized
    vptr = realloc(vptr,10);
    free(vptr);//freeing pointer
    free(iptr);
    res_help = strtol("help", &end, 10);
    res_help = atol("help");
    res_zero = atol("0");

    printf("Got from help: %d, from zero: %d\n", res_help, res_zero);
    if(*end)
        printf("Conversion error, non-convertible part: %s", end); 
    printf("int = %d \n",i);
    printf("lint = %ld \n",li);
    printf("double = %f \n",dbl);
    printf("double2 = %f \n",dbl2);
    printf("double3 = %f \n",dbl3);

    printf("Before sorting the list is: \n");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }
    qsort(values, 5, sizeof(int), cmpfunc);
    printf("\nAfter sorting the list is: \n");
    for( n = 0 ; n < 5; n++ ) {   
        printf("%d ", values[n]);
    } 

       /* using bsearch() to find value 32 in the array */
       item = (int*) bsearch (&key, values, 5, sizeof (int), cmpfunc);
       if( item != NULL ) {
          printf("\nSearching... Found item = %d\n", *item);
       } 
       else {
          printf("\nSearching... Item = %d could not be found\n", *item);
       }
    //if srand is not called before rand srand(1) is assumed
    srand(time(NULL));//adding random seed 
    rand_num = rand();
    printf("Print the rand number %d \n",rand_num);
    if(rand_num % 3 == 0)
    {
        printf("\n END of Program now program will abort\n"); 
        abort();//abnormal terminate 
    }
    else if(rand_num % 3 == 1)
    {
        printf("\n END of Program now program will atexit\n"); 
        atexit(function);
    }
    else
    {   
        printf("\n END of Program, The program will exit\n"); 
        exit(EXIT_SUCCESS);
    }
}
