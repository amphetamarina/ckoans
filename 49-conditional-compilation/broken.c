#include <stdio.h>

// BUG: DEBUG is not defined, but we want to use it
// #define DEBUG 1

#define VERSION 2

int main(void) {
    printf("Program starting...\n");

    // BUG: Wrong condition - should check if DEBUG is defined
    #ifdef RELEASE
        printf("Debug mode active\n");
    #else
        printf("Release mode active\n");
    #endif

    // BUG: Condition is backwards - VERSION is 2, not 1
    #if VERSION < 2
        printf("Version 2.0 or higher\n");
    #elif VERSION == 1
        printf("Version 1.x\n");
    #else
        printf("Unknown version\n");
    #endif

    // BUG: FEATURE_X is not defined, so this won't print
    #ifdef FEATURE_X
        printf("Feature X enabled\n");
    #endif
    // Missing: Should print "Feature X disabled" when not defined

    return 0;
}
