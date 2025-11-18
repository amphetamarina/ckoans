#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Method 1: Union (implementation-defined but widely used)
union IntFloat {
    int i;
    float f;
};

float int_to_float_union(int x) {
    union IntFloat u;
    u.i = x;
    return u.f;  // Read different member - OK with unions
}

// Method 2: memcpy (most portable)
float int_to_float_memcpy(int x) {
    float f;
    memcpy(&f, &x, sizeof(f));  // Safe type punning
    return f;
}

// Method 3: Character array access (always valid)
void print_bytes(void* ptr, size_t size) {
    unsigned char* bytes = (unsigned char*)ptr;  // char* can alias anything
    printf("Bytes: ");
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n");
}

// BUG: Wrong way - pointer cast
float int_to_float_wrong(int x) {
    // return *(float*)&x;  // BUG: Strict aliasing violation!

    // Use correct method instead
    return int_to_float_memcpy(x);
}

int main(void) {
    int x = 0x3f800000;  // 1.0f in IEEE 754

    // Demonstrate all three valid methods
    float f1 = int_to_float_union(x);
    float f2 = int_to_float_memcpy(x);
    float f3 = int_to_float_wrong(x);  // Uses correct method internally

    printf("Union method: %.1f\n", f1);
    printf("Memcpy method: %.1f\n", f2);
    printf("All equal: %s\n", (f1 == f2 && f2 == f3) ? "yes" : "no");

    // Demonstrate char* aliasing
    int value = 42;
    print_bytes(&value, sizeof(value));

    return 0;
}
