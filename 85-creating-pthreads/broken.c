#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// BUG: Wrong signature - should be void* func(void*)
void thread_function(int *id) {
    printf("Thread %d starting\n", *id);
    sleep(1);
    printf("Thread %d finishing\n", *id);
    // BUG: Should return void*, not void
}

int main(void) {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    printf("Creating threads...\n");

    for (int i = 0; i < 3; i++) {
        // BUG: pthread_create needs (void*) cast for the argument
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (result != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    printf("Main thread waiting for completion...\n");

    // BUG: Missing pthread_join calls - threads may not complete before main exits
    // for (int i = 0; i < 3; i++) {
    //     pthread_join(threads[i], NULL);
    // }

    printf("All threads completed\n");

    return 0;
}
