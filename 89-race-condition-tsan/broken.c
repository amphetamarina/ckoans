#include <stdio.h>
#include <pthread.h>

#define NUM_INCREMENTS 100000

int global_counter = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_thread(void *arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        // BUG: Missing mutex lock - TSAN will detect this data race
        // pthread_mutex_lock(&counter_mutex);
        global_counter++;
        // pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

void *decrement_thread(void *arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        // BUG: Missing mutex lock - TSAN will detect this data race
        // pthread_mutex_lock(&counter_mutex);
        global_counter--;
        // pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t inc_thread, dec_thread;

    printf("Starting threads with data race...\n");
    printf("ThreadSanitizer should detect conflicting accesses\n\n");

    pthread_create(&inc_thread, NULL, increment_thread, NULL);
    pthread_create(&dec_thread, NULL, decrement_thread, NULL);

    pthread_join(inc_thread, NULL);
    pthread_join(dec_thread, NULL);

    printf("Final counter value: %d (expected: 0)\n", global_counter);

    if (global_counter == 0) {
        printf("SUCCESS: Counter is correct!\n");
    } else {
        printf("ERROR: Counter is %d, race condition lost some updates!\n", global_counter);
    }

    pthread_mutex_destroy(&counter_mutex);

    return 0;
}
