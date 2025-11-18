#include <stdio.h>

// BUG: Declaration and definition mismatch
int add(int a, int b);  // Declared to take 2 args

int add(int a, int b, int c) {  // BUG: Defined with 3 args!
    return a + b + c;
}

int main(void) {
    int result = add(10, 20);  // BUG: Calling with 2 args, but function expects 3
    printf("%d\n", result);
    return 0;
}
