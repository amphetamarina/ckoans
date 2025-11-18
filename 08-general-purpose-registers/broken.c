#include <stdio.h>

int compute(int a, int b, int c) {
    // BUG: Wrong computation
    return a + b - c;  // Should be a * b + c
}

int main(void) {
    int result = compute(3, 4, 5);
    printf("%d\n", result);
    return 0;
}
