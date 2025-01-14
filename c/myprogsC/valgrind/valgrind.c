/*
 *  Author: Vasudev 
 *  Date: 23rd oct 2020
 *  Purpose: Create a memory leak and verify it with valgrind
 */

//headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
void test1();
void test2();
void test3();
void test4();
char* getstring();

int main()
{
    test1();
    test2();
    test3();
    test4();
    /*
    int *a = malloc(500*(sizeof(int)));
    int *b = malloc(200*(sizeof(int)));
    a[0] =100;
    b[2] = 34;
    free(b);
    return 0;
    */
}

void test1()
{
    const int NUM_HEIGHTS = 3;
    int *heights = malloc(NUM_HEIGHTS);
    for (int i = 0; i < NUM_HEIGHTS; i++) {
        heights[i] = i * i;
        printf("%d: %d\n", i, heights[i]);
    }
    //not freeing pointer after usage of dynamic data
}

void test2()
{
    const int NUM_WEIGHTS = 3;
    int *weights = malloc(NUM_WEIGHTS);
    for (int i = 0; i < NUM_WEIGHTS; i++) {
        weights[i] = i * i;
        printf("%d: %d\n", i, weights[i]);
    }
    free(weights);
    weights[0] = 0; // illegal access of freed pointed
}

void test3()
{
    const int NUM_HEIGHTS = 10;
    int *heights = malloc(NUM_HEIGHTS * sizeof(*heights));
    for (int i = 0; i < NUM_HEIGHTS; i++) {
        if((heights = NULL)) { 
            heights = malloc(NUM_HEIGHTS *sizeof(*heights));
        }
    }
    free(heights);
}

void test4()
{
    printf("string: %s\n", getstring());
}

char* getstring()
{
    char message[100] = "Hello World!";
    char *ret = message;
    return ret;
}

