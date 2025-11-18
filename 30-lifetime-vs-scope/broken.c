#include <stdio.h>

int get_counter(void) {
    // BUG: Missing 'static' - lifetime is only during function execution
    // This resets to 0 on each call (automatic lifetime)
    int counter = 0;
    counter++;
    return counter;
}

void demonstrate_scope(void) {
    // BUG: 'x' is not declared in this scope
    // Even though 'x' exists in main's stack frame,
    // we cannot access it here (scope limitation)
    // printf("Trying to access x: %d\n", x);  // Won't compile
}

int main(void) {
    int x = 42;  // x has block scope and automatic lifetime

    printf("Counter call 1: %d\n", get_counter());  // Should be 1
    printf("Counter call 2: %d\n", get_counter());  // Should be 2
    printf("Counter call 3: %d\n", get_counter());  // Should be 3

    {
        // BUG: This shadows outer 'x', but should accumulate instead
        int x = 0;
        x += 10;
        printf("Inner x: %d\n", x);
    }  // Inner 'x' lifetime ends here (destroyed)

    printf("Outer x: %d\n", x);  // Original x is still 42

    return 0;
}
