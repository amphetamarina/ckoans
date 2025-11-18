#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_counter = 0;  // Global - shared between threads

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;

    // Local variable - each thread has its own copy
    int local_counter = 0;

    for (int i = 0; i < 5; i++) {
        // BUG: Missing synchronization on shared variable
        shared_counter++;
        local_counter++;
    }

    printf("Thread %d: local_counter=%d, shared_counter=%d\n",
           thread_id, local_counter, shared_counter);

    return NULL;
}

int main(void) {
    pthread_t threads[2];
    // BUG: Using same variable address for both threads - they'll see same value
    int thread_ids[2] = {1, 2};

    printf("Initial shared_counter: %d\n\n", shared_counter);

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // BUG: Expecting deterministic result without synchronization
    printf("\nFinal shared_counter: %d (expected: 10)\n", shared_counter);
    printf("Each thread's local_counter was private: should be 5\n");

    return 0;
}
