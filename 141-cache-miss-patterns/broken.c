#include <stdio.h>
#include <stdlib.h>

#define ROWS 4096
#define COLS 4096

int main(void) {
    // Allocate large 2D array
    int (*matrix)[COLS] = malloc(ROWS * sizeof(*matrix));
    if (!matrix) {
        perror("malloc");
        return 1;
    }

    // Initialize
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = i + j;
        }
    }

    long long sum = 0;

    // BUG: Column-major order (j outer, i inner) is cache-hostile
    // C arrays are row-major, so this jumps around memory
    // Should iterate row-major: for (i) { for (j) { ... } }
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            sum += matrix[i][j];
        }
    }

    printf("Sum: %lld\n", sum);

    free(matrix);
    return 0;
}
