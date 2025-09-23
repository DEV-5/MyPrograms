#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define INCREMENTS_PER_THREAD 100000

// A shared global variable that will be atomically incremented
volatile int counter = 0;

void *thread_function(void *arg) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; ++i) {
        // Atomically add 1 to 'counter' and return the new value
        // __sync_add_and_fetch(&counter, 1);
        counter++;
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create multiple threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the final value of the counter
    printf("Final counter value: %d\n", counter);
    printf("Expected counter value: %d\n", NUM_THREADS * INCREMENTS_PER_THREAD);

    return 0;
}
