#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uninitialized_read(void) {
    int x;  // BUG: Not initialized
    if (x > 0) {  // BUG: Reading uninitialized value
        printf("Positive\n");
    } else {
        printf("Non-positive\n");
    }
}

void invalid_write(void) {
    int *arr = malloc(5 * sizeof(int));

    // BUG: Writing past end of allocation
    for (int i = 0; i <= 5; i++) {
        arr[i] = i;
    }

    free(arr);
}

void memory_leak(void) {
    char *leak1 = malloc(100);
    strcpy(leak1, "This will leak");
    // BUG: Never freed

    int *leak2 = malloc(50 * sizeof(int));
    // BUG: Never freed
}

void invalid_free(void) {
    int *ptr = malloc(sizeof(int));
    *ptr = 42;

    free(ptr);
    // BUG: Double free
    free(ptr);
}

void conditional_uninitialized(void) {
    int a, b;

    a = 10;
    // BUG: b is not initialized

    // BUG: Using uninitialized b
    int sum = a + b;
    printf("Sum: %d\n", sum);
}

int main(void) {
    printf("Valgrind Memcheck demonstration:\n\n");

    uninitialized_read();

    invalid_write();

    memory_leak();

    // invalid_free();  // Uncomment to test double-free

    conditional_uninitialized();

    printf("Done\n");
    return 0;
}
