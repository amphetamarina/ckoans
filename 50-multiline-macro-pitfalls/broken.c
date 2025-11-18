#include <stdio.h>

// BUG: Missing do-while(0) wrapper - breaks in if statements
#define PRINT_TWICE(x) \
    printf("First: %d\n", x); \
    printf("Second: %d\n", x)

// BUG: Double evaluation - argument evaluated multiple times
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// BUG: Missing braces and backslash continuation
#define SWAP(a, b) \
    int temp = a; \
    a = b; \
    b = temp

int main(void) {
    int x = 10;
    int y = 20;

    // BUG: Only first printf is inside if - second always executes
    if (x < y)
        PRINT_TWICE(x);
    else
        printf("x >= y\n");

    // BUG: MAX with side effects - increments happen twice
    int a = 5, b = 3;
    int result = MAX(a++, b++);
    printf("Max result: %d (a=%d, b=%d)\n", result, a, b);

    // BUG: SWAP doesn't work due to missing braces
    int m = 100, n = 200;
    if (m < n)
        SWAP(m, n);  // This will cause compilation or logic error
    printf("After swap: m=%d, n=%d\n", m, n);

    return 0;
}
