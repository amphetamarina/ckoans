#include <stdio.h>

// The optimizer assumes different types don't alias
int test_aliasing_assumption(void) {
    int x = 42;
    float y = 3.14f;

    // Optimizer assumes &x and &y don't alias (different types)
    // So it can cache 'x' in a register
    int* px = &x;
    float* py = &y;

    *px = 10;
    *py = 2.5f;

    // Optimizer knows *px hasn't changed (no float* can alias int*)
    return *px;  // Will return 10
}

// The optimizer assumes no signed overflow
int test_overflow_assumption(int x) {
    // BUG: If x is INT_MAX, x + 1 overflows (UB)
    // Optimizer can assume this never happens
    if (x + 1 < x) {
        return -1;  // Optimizer may eliminate this branch!
    }
    return x + 1;
}

// Demonstrate correct code that works with optimizer
int correct_addition(int x, int limit) {
    // Check before adding to avoid overflow
    if (x > limit - 1) {
        return limit;
    }
    return x + 1;
}

int main(void) {
    printf("Aliasing test: %d\n", test_aliasing_assumption());

    // Test overflow - use safe value
    printf("Addition test: %d\n", test_overflow_assumption(41));

    printf("Correct addition: %d\n", correct_addition(41, 100));

    return 0;
}
