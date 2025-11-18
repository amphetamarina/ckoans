#include <stdio.h>

int helper(void) {
    return 100;
}

int main(void) {
    int value = 42;
    // After calling helper(), value should still be 42 (callee-saved)
    int result = helper();
    // BUG: Wrong computation
    printf("%d\n", value + result);  // Should be 142, but let's verify value is preserved
    return 0;
}
