#include <stdio.h>

// Weak symbol - can be overridden
__attribute__((weak)) int get_value(void) {
    return 100;
}

// BUG: This strong symbol should override the weak one above
// but it's commented out, so the weak version is used
/*
int get_value(void) {
    return 42;
}
*/

// Uninitialized global - weak symbol
int weak_global;

// Initialized global - strong symbol
int strong_global = 10;

void initialize_weak(void) {
    // BUG: Should initialize to 32, not 30
    weak_global = 30;
}

int main(void) {
    initialize_weak();

    printf("Value: %d\n", get_value());
    printf("Weak global: %d\n", weak_global);
    printf("Strong global: %d\n", strong_global);

    return 0;
}
