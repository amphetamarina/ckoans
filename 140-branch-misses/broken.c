#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int *data = malloc(SIZE * sizeof(int));
    if (!data) {
        perror("malloc");
        return 1;
    }

    // Initialize with random data
    srand(42);  // Fixed seed for reproducibility
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 256;
    }

    // BUG: Processing unsorted data causes unpredictable branches
    // Should sort first: qsort(data, SIZE, sizeof(int), compare);

    long long sum = 0;
    for (int i = 0; i < SIZE; i++) {
        // Unpredictable branch - random data means ~50% miss rate
        if (data[i] >= 128) {
            sum += data[i];
        }
    }

    printf("Sum of values >= 128: %lld\n", sum);

    free(data);
    return 0;
}
