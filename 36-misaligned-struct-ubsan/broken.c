#include <stdio.h>
#include <string.h>

struct Data {
    int x;
    int y;
    double z;
};

int main(void) {
    // Create a buffer
    char buffer[64];

    // BUG: Create misaligned pointer - offset by 1 byte
    // struct Data requires alignment (usually 8 bytes for the double)
    char* misaligned = buffer + 1;
    struct Data* data_ptr = (struct Data*)misaligned;  // BUG: Misaligned!

    // BUG: This is undefined behavior - misaligned access
    // UBSan will detect this!
    // data_ptr->x = 10;
    // data_ptr->y = 20;
    // data_ptr->z = 3.14;

    // Correct approach: ensure proper alignment
    // Use aligned buffer or proper offset
    struct Data aligned_data;
    aligned_data.x = 10;
    aligned_data.y = 20;
    aligned_data.z = 3.14;

    printf("x = %d\n", aligned_data.x);
    printf("y = %d\n", aligned_data.y);
    printf("z = %.2f\n", aligned_data.z);

    // Alternative: use memcpy for unaligned access
    struct Data copy;
    memcpy(&copy, misaligned, sizeof(struct Data));  // Safe unaligned read

    return 0;
}
