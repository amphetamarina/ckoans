#include <stdio.h>

// BUG: Macro has wrong formula - expands to incorrect calculation
#define COMPUTE(x, y) ((x) + (y) * 2)

// BUG: This macro is missing parentheses around entire expression
#define AVERAGE(a, b) (a) + (b) / 2

int main(void) {
    // BUG: COMPUTE should be (x * 2) + (y * 3)
    int result1 = COMPUTE(5, 10);
    printf("Compute 5, 10: %d\n", result1);

    // BUG: AVERAGE(10, 20) * 2 expands to 10 + 20 / 2 * 2 = 30, not 30
    // Should be (10 + 20) / 2 = 15
    int result2 = AVERAGE(10, 20);
    printf("Average 10, 20: %d\n", result2);

    // BUG: When multiplied, precedence issue appears
    int result3 = AVERAGE(6, 8) * 2;
    printf("Average(6, 8) * 2: %d\n", result3);

    return 0;
}
