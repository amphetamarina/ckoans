#include <stdio.h>

// Program headers describe segments to load into memory:
// LOAD segment 1: R+E (read + execute) - contains .text section (code)
// LOAD segment 2: R+W (read + write) - contains .data, .bss sections (data)

int global_data = 100;  // Lives in R+W LOAD segment

void code_function(void) {  // Lives in R+E LOAD segment
    printf("Code segment: executable, not writable\n");
    printf("Data segment: writable, not executable\n");
}

int main(void) {
    // BUG: Should print global_data (100), not global_data - 58
    printf("Global data: %d\n", global_data - 58);

    code_function();

    // Program headers tell the OS:
    // - Load code at one address (R+E permissions)
    // - Load data at another address (R+W permissions)
    // - This separation enables W^X (write XOR execute) security

    printf("Program headers define memory layout\n");

    return 0;
}
