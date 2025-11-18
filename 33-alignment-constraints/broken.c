#include <stdio.h>
#include <stdint.h>
#include <stdalign.h>

int main(void) {
    // Show alignment requirements
    printf("Alignment of char: %zu\n", alignof(char));
    printf("Alignment of short: %zu\n", alignof(short));
    printf("Alignment of int: %zu\n", alignof(int));
    printf("Alignment of long: %zu\n", alignof(long));
    printf("Alignment of double: %zu\n", alignof(double));

    // Demonstrate alignment in arrays
    char buffer[32];

    // BUG: Creating misaligned pointer
    // buffer might not be aligned for int access
    char* char_ptr = buffer + 1;  // Definitely not 4-byte aligned
    int* int_ptr = (int*)char_ptr;  // BUG: Misaligned cast!

    // This might crash or give wrong results on some architectures
    // *int_ptr = 42;  // BUG: Misaligned write - undefined behavior!

    // Correct approach: use properly aligned buffer
    // Or use memcpy for unaligned access
    alignas(int) char aligned_buffer[32];
    int* aligned_int_ptr = (int*)aligned_buffer;
    *aligned_int_ptr = 42;
    printf("Aligned write: %d\n", *aligned_int_ptr);

    return 0;
}
