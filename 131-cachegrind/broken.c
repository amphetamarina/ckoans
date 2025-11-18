#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

// BUG: Column-major traversal on row-major storage (poor cache locality)
void sum_columns_slow(int matrix[SIZE][SIZE], long *sums) {
    for (int col = 0; col < SIZE; col++) {
        sums[col] = 0;
        // BUG: Accessing matrix[row][col] jumps across cache lines
        for (int row = 0; row < SIZE; row++) {
            sums[col] += matrix[row][col];
        }
    }
}

// Fixed version with better cache locality
// void sum_columns_fast(int matrix[SIZE][SIZE], long *sums) {
//     for (int col = 0; col < SIZE; col++) {
//         sums[col] = 0;
//     }
//     for (int row = 0; row < SIZE; row++) {
//         for (int col = 0; col < SIZE; col++) {
//             sums[col] += matrix[row][col];
//         }
//     }
// }

// BUG: Random access pattern causes cache misses
void process_random_access(int *data, int *indices, int count) {
    for (int i = 0; i < count; i++) {
        // BUG: Random jumps through memory
        data[indices[i]]++;
    }
}

// Fixed version with sequential access
// void process_sequential(int *data, int count) {
//     for (int i = 0; i < count; i++) {
//         data[i]++;
//     }
// }

int main(void) {
    printf("Cachegrind cache analysis:\n\n");

    // Allocate and initialize matrix
    int (*matrix)[SIZE] = malloc(sizeof(int[SIZE][SIZE]));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = i + j;
        }
    }

    // BUG: Poor cache locality
    long *sums = malloc(SIZE * sizeof(long));
    sum_columns_slow(matrix, sums);

    printf("Column sums (first 5): ");
    for (int i = 0; i < 5; i++) {
        printf("%ld ", sums[i]);
    }
    printf("\n");

    free(matrix);
    free(sums);

    // Random access test
    int *data = malloc(100000 * sizeof(int));
    int *indices = malloc(50000 * sizeof(int));

    for (int i = 0; i < 100000; i++) {
        data[i] = 0;
    }
    for (int i = 0; i < 50000; i++) {
        indices[i] = (i * 7919) % 100000;  // Pseudo-random
    }

    process_random_access(data, indices, 50000);

    free(data);
    free(indices);

    printf("Processing complete\n");
    return 0;
}
