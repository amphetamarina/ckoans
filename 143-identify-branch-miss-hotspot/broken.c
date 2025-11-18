#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

// Well-predicted function - simple pattern
long long simple_filter(int *data, int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {  // Predictable pattern
            sum += data[i];
        }
    }
    return sum;
}

// BUG: Branch-miss hotspot - random data causes unpredictable branches
// This function will dominate branch-misses in perf report
long long complex_filter(int *data, int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        // Unpredictable branch on random data
        if (data[i] > 128) {
            sum += data[i];
        }
        // Another unpredictable branch
        if (data[i] % 7 == 0) {
            sum -= data[i] / 2;
        }
    }
    return sum;
}

// Another well-predicted function
long long range_filter(int *data, int size) {
    long long sum = 0;
    for (int i = 0; i < size / 2; i++) {  // Predictable: always first half
        sum += data[i];
    }
    return sum;
}

int main(void) {
    int *data = malloc(SIZE * sizeof(int));
    if (!data) {
        perror("malloc");
        return 1;
    }

    // Initialize with random data
    srand(42);
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 256;
    }

    long long result = 0;

    // Run all filters multiple times
    for (int iter = 0; iter < 100; iter++) {
        result += simple_filter(data, SIZE);
        result += complex_filter(data, SIZE);  // Branch-miss hotspot!
        result += range_filter(data, SIZE);
    }

    printf("Final result: %lld\n", result);

    free(data);
    return 0;
}
