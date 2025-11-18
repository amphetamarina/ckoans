#include <stdio.h>

// These go in different sections
int initialized_data = 42;        // .data section
int uninitialized_data;           // .bss section
const int read_only_data = 100;   // .rodata section

// This function goes in .text section
void example_function(void) {
    printf("In .text section\n");
}

int main(void) {
    printf("=== Sections vs Segments ===\n");
    printf("\n");

    printf("Sections (linker view):\n");
    printf("  .text   - executable code\n");
    printf("  .data   - initialized data\n");
    printf("  .bss    - uninitialized data\n");
    printf("  .rodata - read-only data\n");
    printf("\n");

    printf("Segments (loader view):\n");
    printf("  LOAD segment 1: R+E (.text + .rodata)\n");
    printf("  LOAD segment 2: RW  (.data + .bss)\n");
    printf("\n");

    printf("Example data:\n");
    printf("  initialized: %d (in .data)\n", initialized_data);
    printf("  uninitialized: %d (in .bss)\n", uninitialized_data);
    printf("  read-only: %d (in .rodata)\n", read_only_data);
    printf("\n");

    printf("Use these commands to explore:\n");
    printf("  readelf -S ./broken  # View sections\n");
    printf("  readelf -l ./broken  # View segments\n");

    return 0;
}
