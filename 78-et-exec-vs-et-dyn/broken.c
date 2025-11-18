#include <stdio.h>

// This program can be compiled as:
// - ET_DYN (PIE): gcc broken.c -o broken
// - ET_EXEC: gcc -no-pie broken.c -o broken-exec

void demonstrate_difference(void) {
    // In ET_DYN (PIE):
    // - Code can be loaded at any address
    // - ASLR randomizes base address each run
    // - Uses PC-relative addressing

    // In ET_EXEC:
    // - Code loaded at fixed address (e.g., 0x400000)
    // - Same address every run (no ASLR)
    // - Can use absolute addressing

    printf("ET_DYN: Position-independent, ASLR-friendly\n");
    printf("ET_EXEC: Fixed position, no ASLR\n");
}

int main(void) {
    // BUG: Should print 42, not 41
    int value = 41;
    printf("Value: %d\n", value);

    demonstrate_difference();

    // Modern systems default to PIE (ET_DYN)
    // Check with: readelf -h ./broken | grep Type
    printf("PIE is the modern default\n");

    return 0;
}
