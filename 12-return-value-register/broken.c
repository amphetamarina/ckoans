#include <stdio.h>

int calculate(int x) {
    int result = x * x + x;
    // BUG: Not returning the computed value
    return 0;  // Should return result
}

int main(void) {
    int val = calculate(5);
    printf("%d\n", val);
    return 0;
}
