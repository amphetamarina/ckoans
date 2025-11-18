#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int data = 0;
int ready = 0;

void *writer_thread(void *arg) {
    printf("Writer: Setting data to 42\n");
    // BUG: Should use atomic store with release semantics
    data = 42;

    // BUG: Should use atomic store with release semantics
    // Without memory barrier, ready might be set before data
    ready = 1;

    printf("Writer: Signaled ready\n");
    return NULL;
}

void *reader_thread(void *arg) {
    printf("Reader: Waiting for data to be ready\n");

    // BUG: Should use atomic load with acquire semantics
    // Busy-wait without proper memory ordering
    while (ready == 0) {
        // Spin
    }

    // BUG: Should use atomic load
    // Without memory barrier, might see old value of data
    printf("Reader: Data is ready, value = %d\n", data);

    if (data == 42) {
        printf("Reader: SUCCESS - Got expected value!\n");
    } else {
        printf("Reader: ERROR - Memory ordering violation! Got %d instead of 42\n", data);
    }

    return NULL;
}

int main(void) {
    pthread_t writer, reader;

    printf("Demonstrating memory barriers\n\n");

    pthread_create(&reader, NULL, reader_thread, NULL);
    sleep(1);  // Give reader time to start waiting
    pthread_create(&writer, NULL, writer_thread, NULL);

    pthread_join(writer, NULL);
    pthread_join(reader, NULL);

    printf("\nMemory barriers ensure proper ordering!\n");

    return 0;
}
