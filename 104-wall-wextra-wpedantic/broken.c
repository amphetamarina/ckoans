#include <stdio.h>

// BUG: Missing return type (should be int)
compute(int x) {
    // BUG: Unused variable
    int unused_var = 42;

    // BUG: Implicit conversion from float to int
    return x * 1.5;
}

// BUG: Extra semicolon (ISO C does not allow extra ';' outside of a function)
int helper(void) {
    return 10;
};

int main(void) {
    // BUG: Unused variable
    int result;

    // BUG: Signed/unsigned comparison
    int i;
    unsigned int limit = 5;
    for (i = -1; i < limit; i++) {
        printf("%d\n", compute(i));
    }

    // BUG: Missing return statement (falls through)
}
