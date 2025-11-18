#include <stdio.h>

int compute(int a, int b, int c, int d, int e) {
    int x1 = a + b;
    int x2 = c + d;
    int x3 = e + a;
    int x4 = b + c;
    int x5 = d + e;
    int x6 = a + c;
    int x7 = b + d;
    int x8 = c + e;

    // BUG: Missing x8 in the sum
    int result = x1 + x2 + x3 + x4 + x5 + x6 + x7;

    return result;
}

int main(void) {
    int result = compute(1, 2, 3, 4, 5);
    printf("Result: %d\n", result);

    // Show that address-taken variables must live on stack
    int stack_var = 42;
    int *ptr = &stack_var;  // Taking address forces stack allocation
    printf("Address taken, must be on stack: %d\n", *ptr);

    return 0;
}
