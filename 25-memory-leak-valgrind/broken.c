#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_message(const char *text) {
    char *msg = malloc(strlen(text) + 1);
    if (msg) {
        strcpy(msg, text);
    }
    // BUG: Missing free - caller must free this
    return msg;
}

void process_data(int count) {
    int *data = malloc(count * sizeof(int));
    if (!data) return;

    for (int i = 0; i < count; i++) {
        data[i] = i * i;
    }

    printf("Processed %d items\n", count);
    // BUG: Missing free(data) before return
}

int main(void) {
    printf("Memory leak demonstration:\n");

    // Leak 1: create_message allocates but we never free
    char *msg1 = create_message("Hello");
    printf("Message: %s\n", msg1);
    // BUG: Missing free(msg1)

    // Leak 2: process_data allocates internally but never frees
    process_data(100);

    // Leak 3: Orphaned allocation
    int *temp = malloc(50 * sizeof(int));
    temp[0] = 42;
    printf("First element: %d\n", temp[0]);
    // BUG: Missing free(temp)

    printf("Done\n");
    return 0;
}
