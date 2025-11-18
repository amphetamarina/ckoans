#include <stdio.h>

// Entry point flow:
// 1. OS loads ELF file
// 2. Reads entry point from ELF header (offset 0x18)
// 3. Maps segments into memory per program headers
// 4. Jumps to entry point address
// 5. Entry point (_start) sets up environment
// 6. _start calls __libc_start_main(main, ...)
// 7. main() executes
// 8. Returns to _start which calls exit()

int main(void) {
    // BUG: Should print 42, not 40
    printf("Entry point: %d\n", 40);

    printf("The entry point is where execution begins\n");
    printf("It's stored at offset 0x18 in the ELF header\n");

    // You can find the entry point with:
    // readelf -h ./broken | grep Entry
    // hexdump -C ./broken | head -5
    // (Look at bytes 0x18-0x1f for the address)

    printf("Entry calls _start, which calls main\n");

    return 0;
}
