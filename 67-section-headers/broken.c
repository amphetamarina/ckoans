#include <stdio.h>

// Initialized global -> .data section
int initialized_global = 100;  // BUG: Should be 42

// Uninitialized global -> .bss section
int uninitialized_global;

// Constant string -> .rodata section
const char *message = "Hello from .rodata";

// Function -> .text section
int compute_value(int x) {
    // BUG: Should return x * 2
    return x;
}

int main(void) {
    uninitialized_global = 10;

    printf("Initialized: %d\n", initialized_global);
    printf("Computed: %d\n", compute_value(initialized_global));
    printf("Uninitialized: %d\n", uninitialized_global);
    printf("Message: %s\n", message);

    return 0;
}
