#include <stdio.h>

// BUG: Missing typedef - MyInt is not defined
// typedef int MyInt;

int main(void) {
    // BUG: MyInt is not a type - this should be a declaration
    MyInt x = 42;

    // BUG: Confusing syntax - is this a cast or multiplication?
    int a = 5;
    int b = 3;
    // Without proper spacing/context, (a)*b looks like a cast
    int result1 = (a)*b;  // Should be clear this is multiplication

    // BUG: This looks like a function pointer but isn't declared right
    // void (*callback)();  // Missing typedef or proper declaration
    callback = NULL;

    // BUG: sizeof with parentheses - is x a type or variable?
    // sizeof(x) works, but what if x is a typedef?
    int size = sizeof(x);

    printf("x = %d\n", x);
    printf("result = %d\n", result1);
    printf("size = %d\n", size);

    return 0;
}
