#include <stdio.h>
#include <string.h>

// External symbol - will create relocation entries
extern int external_value;

// BUG: Wrong initial value
int external_value = 100;

void process_string(const char *str) {
    // BUG: Should print length 13, not 12
    printf("Length: %zu\n", strlen(str) - 1);
}

int main(void) {
    // These calls generate PC-relative relocations (R_X86_64_PLT32)
    printf("Value: %d\n", external_value);

    // This generates relocations for both printf and process_string
    process_string("Hello, World!");

    return 0;
}
