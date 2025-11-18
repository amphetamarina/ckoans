#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Declared variable - effective type is 'int'
    int x = 42;

    // Valid: access through int*
    int* p_int = &x;
    printf("Via int*: %d\n", *p_int);

    // Valid: access through unsigned int* (signed/unsigned variant)
    unsigned int* p_uint = (unsigned int*)&x;
    printf("Via unsigned int*: %u\n", *p_uint);

    // Valid: access through char* (character type can alias anything)
    unsigned char* p_char = (unsigned char*)&x;
    printf("Via char* (byte 0): %u\n", p_char[0]);

    // Allocated memory - effective type determined by first write
    void* mem = malloc(sizeof(double));
    if (!mem) return 1;

    // BUG: First write determines effective type
    // Writing as double makes effective type 'double'
    *(double*)mem = 3.14;

    // BUG: Now reading as int* violates strict aliasing!
    // The effective type is double, not int
    // This is undefined behavior (but we'll comment it out to avoid issues)
    // int* p_wrong = (int*)mem;
    // printf("Wrong type access: %d\n", *p_wrong);  // BUG: UB!

    // Correct: read as the same type we wrote
    double* p_correct = (double*)mem;
    printf("Correct access: %.2f\n", *p_correct);

    free(mem);

    return 0;
}
