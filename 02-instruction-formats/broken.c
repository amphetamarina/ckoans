#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 5;
    int result;

    // BUG: Incorrect arithmetic operation order
    result = a + 2 * b;  // Should be (a * 2) + b = 25, not a + (2 * b) = 20

    printf("Result: %d\n", result);
    return 0;
}
