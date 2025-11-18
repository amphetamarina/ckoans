#include <stdio.h>

// Original API (VERS_1.0) - took single int parameter
int process_data_v1(int value) {
    printf("  V1: Processing single value: %d\n", value);
    return value * 2;
}

// New API (VERS_2.0) - takes two parameters (ABI break!)
int process_data_v2(int value, int multiplier) {
    printf("  V2: Processing with multiplier: %d * %d\n", value, multiplier);
    return value * multiplier;
}

// Simulating version script behavior
// In real code, we'd use .symver assembly directives:
// __asm__(".symver process_data_v1,process_data@VERS_1.0");
// __asm__(".symver process_data_v2,process_data@@VERS_2.0");

// Default version (should call v2)
int process_data(int value, int multiplier) {
    // BUG: Should use process_data_v2
    return process_data_v1(value);
}

void demonstrate_abi_compatibility(void) {
    printf("\nABI Compatibility Demonstration:\n");

    // Old client compiled against VERS_1.0
    printf("Old client (linked to @VERS_1.0):\n");
    int result_old = process_data_v1(10);
    printf("  Result: %d\n", result_old);

    // New client compiled against VERS_2.0 (default @@)
    printf("\nNew client (linked to @@VERS_2.0):\n");
    int result_new = process_data_v2(10, 3);
    printf("  Result: %d\n", result_new);

    // Default should use v2
    printf("\nDefault version:\n");
    // BUG: Should return 30 (10 * 3)
    int result_default = process_data(10, 3);
    printf("  Result: %d\n", result_default);
}

int main(void) {
    printf("ABI Break Fix with Version Script\n");
    printf("==================================\n");

    demonstrate_abi_compatibility();

    printf("\nVersion scripts maintain backward compatibility\n");
    printf("Old binaries use @VERS_1, new binaries use @@VERS_2\n");

    return 0;
}
