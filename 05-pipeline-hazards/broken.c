#include <stdio.h>

int main(void) {
    // BUG: Long dependency chain - each operation depends on previous
    int x = 1;
    x = x + 1;  // Must wait for previous x
    x = x * 2;  // Must wait for previous x
    x = x + 3;  // Must wait for previous x
    x = x * 4;  // Must wait for previous x

    // Better: Independent computations that can pipeline
    // int a = 1 + 1;
    // int b = 2 * 2;
    // int c = 3 + 3;
    // int x = (a * b) + c;

    printf("Result: %d\n", x);  // Should be 36: ((((1+1)*2)+3)*4) = ((4+3)*4) = 28
    // BUG: Actually it's 28, not 36!
    return 0;
}
