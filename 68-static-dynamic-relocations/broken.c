#include <stdio.h>

// Internal function - static relocation (resolved at link time)
int internal_add(int a, int b) {
    // BUG: Should return a + b
    return a - b;
}

// Another internal function
void internal_print(int value) {
    // printf is in libc.so - dynamic relocation (resolved at runtime)
    printf("Internal value: %d\n", value);
}

int main(void) {
    int result = internal_add(30, 12);

    // printf is external (libc.so) - dynamic relocation
    printf("Result: %d\n", result);

    // internal_print is internal - static relocation
    internal_print(result);

    return 0;
}
