#include <stdio.h>
#include <string.h>

// BUG: Strict aliasing violation - accessing int through float*
float int_as_float_wrong(int x) {
    // BUG: This violates strict aliasing!
    // Compiler assumes float* and int* don't alias
    // return *(float*)&x;  // BUG: Undefined behavior!

    // Correct: use memcpy for type punning
    float f;
    memcpy(&f, &x, sizeof(f));
    return f;
}

// Another common violation
int alias_violation(void) {
    int x = 42;
    // BUG: Aliasing int through short*
    short* p = (short*)&x;  // BUG: strict aliasing violation!

    // Reading is UB, but we'll show the correct way
    // return *p;  // BUG: Would be UB

    // Correct: use char* or memcpy
    unsigned char* cp = (unsigned char*)&x;
    return cp[0] | (cp[1] << 8);
}

int main(void) {
    int x = 0x3f800000;  // Bit pattern for 1.0f in IEEE 754

    // Show the violation and correct approach
    float result = int_as_float_wrong(x);
    printf("Type-punned value: %.1f\n", result);

    // Demonstrate proper byte access
    int value = 0x1234;
    unsigned char* bytes = (unsigned char*)&value;
    printf("First byte: 0x%02x\n", bytes[0]);

    return 0;
}
