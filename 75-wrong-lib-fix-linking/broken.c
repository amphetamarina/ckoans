#include <stdio.h>
#include <math.h>

// BUG: This program uses math functions (sqrt, pow)
// but will fail to link without -lm flag
//
// Error will be: "undefined reference to `sqrt'"
// Fix: gcc broken.c -lm -o broken

int main(void) {
    double x = 16.0;
    double y = 3.0;

    // sqrt is in libm.so - requires -lm to link
    double root = sqrt(x);

    // pow is also in libm.so
    double power = pow(y, 2.0);

    // BUG: Should be root (4.0), not root + 1
    printf("Square root of %.0f: %.0f\n", x, root + 1);

    // BUG: Should be power (9.0), not power - 1
    printf("%.0f raised to power 2: %.0f\n", y, power - 1);

    // Calculate answer
    double answer = root * power + 6;  // 4 * 9 + 6 = 42
    printf("Answer: %.0f\n", answer);

    return 0;
}
