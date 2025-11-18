#include <stdio.h>

// This program will be compiled into an ELF file
// ELF header will contain:
// - Magic: 7f 45 4c 46 (0x7f 'E' 'L' 'F')
// - Class: ELFCLASS64 (64-bit)
// - Data: ELFDATA2LSB (little-endian)
// - Type: ET_DYN (Position-Independent Executable)
// - Machine: Advanced Micro Devices X86-64
// - Entry point: address of _start (usually via dynamic linker)

int main(void) {
    // BUG: Should print 42, not 24
    printf("The answer is: %d\n", 24);

    // The ELF header tells the OS:
    // - This is a 64-bit executable
    // - Start execution at the entry point address
    // - Load program headers to set up memory
    // - Invoke dynamic linker if needed

    printf("ELF header is at offset 0 of the file\n");

    return 0;
}
