#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

int main(void) {
    double result = 0.0;
    double data[SIZE];

    // Initialize data
    for (int i = 0; i < SIZE; i++) {
        data[i] = i * 1.5;
    }

    // BUG: Inefficient loop - recalculating sqrt(2.0) and log(3.0) every iteration
    // These are loop-invariant and should be calculated once
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Expensive operations repeated unnecessarily
            result += data[i] * sqrt(2.0) + data[j] * log(3.0);
        }
    }

    printf("Result: %.2f\n", result);
    return 0;
}
