#include <stdio.h>

// BUG: Uses __builtin_cpu_supports which requires runtime checks
// The implementation assumes SSE2 is available
void check_cpu_features(void) {
    // BUG: Should check if CPU supports these features first
    #if defined(__SSE2__)
    printf("SSE2: available\n");
    #else
    printf("SSE2: not available\n");
    #endif

    #if defined(__AVX__)
    printf("AVX: available\n");
    #else
    printf("AVX: not available\n");
    #endif

    #if defined(__AVX2__)
    printf("AVX2: available\n");
    #else
    printf("AVX2: not available\n");
    #endif
}

// BUG: Assumes 64-bit pointers
void pointer_size_assumption(void) {
    // This is fragile - assumes pointer is 8 bytes
    unsigned long addr = (unsigned long)&pointer_size_assumption;
    printf("Function address: 0x%lx\n", addr);

    // BUG: Should use sizeof(void*) or check architecture
    if (sizeof(void*) == 8) {
        printf("Pointer size: 8 bytes (64-bit)\n");
    } else {
        printf("Pointer size: 4 bytes (32-bit)\n");
    }
}

// BUG: Inline assembly assumes x86_64
int get_cpu_id(void) {
    unsigned int eax = 0;
    #if defined(__x86_64__) || defined(__i386__)
    __asm__ __volatile__ (
        "cpuid"
        : "=a" (eax)
        : "a" (0)
        : "ebx", "ecx", "edx"
    );
    #else
    eax = 0;  // BUG: Should handle non-x86 architectures
    #endif
    return eax;
}

int main(void) {
    printf("CPU Feature Detection:\n");
    check_cpu_features();

    printf("\nArchitecture Info:\n");
    pointer_size_assumption();

    printf("\nCPUID max leaf: 0x%x\n", get_cpu_id());

    return 0;
}
