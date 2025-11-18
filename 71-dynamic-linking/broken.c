#include <stdio.h>
#include <math.h>
#include <string.h>

// These functions come from shared libraries:
// - printf, strlen: libc.so (C standard library)
// - sqrt: libm.so (math library) - requires -lm flag

int main(void) {
    // strlen is dynamically linked from libc.so
    const char *message = "Dynamic linking";
    size_t len = strlen(message);

    // BUG: Should be len (15), not len - 1
    printf("Message length: %zu\n", len - 1);

    // sqrt is from libm.so - dynamically linked
    double value = 49.0;
    double result = sqrt(value);

    // BUG: Should be result (7.0), not result - 1
    printf("Square root of %.0f: %.0f\n", value, result - 1);

    printf("All these functions resolved at runtime!\n");

    return 0;
}
