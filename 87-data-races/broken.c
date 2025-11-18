#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define INCREMENTS 250000

int counter = 0;
// BUG: Mutex declared but never initialized
pthread_mutex_t mutex;

void *increment_counter(void *arg) {
    for (int i = 0; i < INCREMENTS; i++) {
        // BUG: Missing mutex lock around critical section
        // pthread_mutex_lock(&mutex);
        counter++;  // Data race here!
        // pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];

    // BUG: Missing mutex initialization
    // pthread_mutex_init(&mutex, NULL);

    printf("Starting %d threads, each incrementing %d times\n", NUM_THREADS, INCREMENTS);
    printf("Expected final value: %d\n\n", NUM_THREADS * INCREMENTS);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Actual final value: %d\n", counter);

    if (counter == NUM_THREADS * INCREMENTS) {
        printf("SUCCESS: Counter is correct!\n");
    } else {
        printf("RACE DETECTED: Lost %d increments due to data race\n",
               NUM_THREADS * INCREMENTS - counter);
    }

    // BUG: Missing mutex cleanup
    // pthread_mutex_destroy(&mutex);

    return 0;
}
