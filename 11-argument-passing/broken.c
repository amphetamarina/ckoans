#include <stdio.h>

// BUG: Arguments in wrong order
int subtract(int a, int b) {
    return b - a;  // Should be a - b
}

int main(void) {
    int result = subtract(10, 3);
    printf("%d\n", result);
    return 0;
}
