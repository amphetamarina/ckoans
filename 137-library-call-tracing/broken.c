#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *prefix = "Hello, ";
    const char *name = "ltrace";
    const char *suffix = " debugging!";

    // BUG: Buffer too small for concatenation
    // Need strlen(prefix) + strlen(name) + strlen(suffix) + 1 = 27 bytes
    char result[10];  // Only 10 bytes!

    strcpy(result, prefix);
    strcat(result, name);
    strcat(result, suffix);

    // This will likely crash or produce garbage due to buffer overflow
    printf("%s\n", result);

    return 0;
}
