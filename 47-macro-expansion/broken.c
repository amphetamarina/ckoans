#include <stdio.h>

// BUG: Missing parentheses - will cause precedence issues
#define SQUARE(x) x * x
#define ADD(a, b) a + b
#define MULTIPLY(a, b) a * b

int main(void) {
    // BUG: SQUARE(2 + 3) expands to 2 + 3 * 2 + 3 = 11, not 25
    int result1 = SQUARE(2 + 3);
    printf("Square of (2+3): %d\n", result1);

    // BUG: MULTIPLY(2+3, 4+5) expands to 2+3 * 4+5 = 17, not 45
    int result2 = MULTIPLY(2 + 3, 4 + 5);
    printf("Multiply (2+3) * (4+5): %d\n", result2);

    // BUG: ADD(10, 20) * 2 expands to 10 + 20 * 2 = 50, not 60
    int result3 = ADD(10, 20) * 2;
    printf("(10 + 20) * 2: %d\n", result3);

    return 0;
}
