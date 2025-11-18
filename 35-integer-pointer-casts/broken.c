#include <stdio.h>
#include <stdint.h>

int main(void) {
    int value = 42;
    int* ptr = &value;

    // BUG: Unsafe - 'int' might be 32-bit while pointer is 64-bit
    // This will truncate on 64-bit systems!
    unsigned int addr_wrong = (unsigned int)(uintptr_t)ptr;  // BUG: Potential truncation

    // Correct: use uintptr_t for pointer-sized integers
    uintptr_t addr_correct = (uintptr_t)ptr;

    // Round-trip conversion
    uintptr_t addr_int = (uintptr_t)ptr;
    int* ptr_back = (int*)addr_int;

    printf("Values match: %s\n", (ptr == ptr_back) ? "yes" : "no");
    printf("Dereferenced value: %d\n", *ptr_back);

    // Check alignment using integer cast
    uintptr_t addr = (uintptr_t)ptr;
    printf("Alignment check (addr %% 4): %lu\n", addr % 4);

    // BUG: Creating pointer from arbitrary integer (undefined behavior)
    // uintptr_t fake_addr = 0x12345678;
    // int* fake_ptr = (int*)fake_addr;  // BUG: Invalid pointer!
    // *fake_ptr = 99;  // BUG: Will likely crash

    return 0;
}
