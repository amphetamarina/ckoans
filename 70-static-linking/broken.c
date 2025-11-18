#include <stdio.h>

// Simulating a static library function
// In real scenarios, this would be in a separate .o file
// compiled into a .a static library

int library_multiply(int a, int b) {
    // BUG: Should return a * b
    return a + b;
}

int library_square(int x) {
    // This simulates calling another library function
    return library_multiply(x, x);
}

int main(void) {
    // When statically linked, all this code becomes part of
    // the final executable at link time
    int result = library_square(7);

    printf("Result: %d\n", result);
    printf("Static linking embeds library code in executable\n");

    return 0;
}
