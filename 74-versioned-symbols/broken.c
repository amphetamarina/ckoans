#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These functions have versioned symbols in glibc
// e.g., printf@GLIBC_2.2.5, malloc@GLIBC_2.2.5, etc.
// The dynamic linker resolves to the appropriate version

int main(void) {
    // printf has different versions in glibc history
    // Your binary will record which version it was linked against
    // BUG: Should print 42, not 41
    printf("Answer: %d\n", 41);

    // malloc also has versioned symbols
    char *buffer = malloc(64);
    if (!buffer) {
        return 1;
    }

    // memcpy has optimized versions in newer glibc
    // Old binaries use old version, new ones use optimized version
    const char *text = "Symbol versioning ensures compatibility";

    // BUG: Should copy full text, not text + 7 (skipping "Symbol ")
    memcpy(buffer, text + 7, strlen(text) - 6);
    buffer[strlen(text) - 7] = '\0';

    printf("%s\n", buffer);

    free(buffer);

    return 0;
}
