#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// BUG: Inefficient function - recalculates expensive operations repeatedly
double slow_computation(int n) {
    double result = 0.0;
    for (int i = 0; i < 10000; i++) {
        result += sin(n + i) * cos(n + i);
    }
    return result;
}

double helper_function(int x) {
    // This calls the slow function unnecessarily
    return slow_computation(x) + slow_computation(x * 2);
}

double process_data(int value) {
    return helper_function(value) * 1.5;
}

int main(void) {
    double total = 0.0;

    // This will spend most time in slow_computation
    for (int i = 0; i < 1000; i++) {
        total += process_data(i);
    }

    printf("Result: %.2f\n", total);
    return 0;
}
