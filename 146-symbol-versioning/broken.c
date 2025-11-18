#include <stdio.h>

// Simulating symbol versioning
// In real shared libraries, we'd use .symver directives

// Version 1.0 - original implementation
int compute_v1(int x) {
    // Original behavior: just double it
    return x * 2;
}

// Version 2.0 - new implementation with additional logic
int compute_v2(int x) {
    // New behavior: double and add 10
    return x * 2 + 10;
}

// Default version (latest)
int compute(int x) {
    // BUG: Should call compute_v2, not compute_v1
    return compute_v1(x);
}

// Demonstrating multiple symbol versions
void show_versioning(void) {
    printf("Symbol versioning allows ABI evolution\n");

    int value = 5;

    // Old client would bind to compute@VERS_1.0
    int result_v1 = compute_v1(value);
    printf("Version 1.0 result: %d\n", result_v1);

    // New client would bind to compute@@VERS_2.0 (default)
    int result_v2 = compute_v2(value);
    printf("Version 2.0 result: %d\n", result_v2);

    // Default version
    int result_default = compute(value);
    // BUG: Should be 20, not 10
    printf("Default version result: %d\n", result_default);
}

int main(void) {
    printf("Symbol Versioning Test\n");
    show_versioning();
    printf("Both versions can coexist in same library\n");
    return 0;
}
