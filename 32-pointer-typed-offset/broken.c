#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    printf("Element 0: %d\n", *ptr);

    // BUG: Trying to manually calculate byte offset
    // ptr + 4 moves by 4 ints (16 bytes), not 1 int (4 bytes)
    ptr = ptr + 4;  // BUG: Should be ptr + 1 for second element
    printf("Element 1: %d\n", *ptr);

    // Reset
    ptr = arr;

    // Demonstrate correct pointer arithmetic
    for (int i = 0; i < 5; i++) {
        // BUG: Incorrectly multiplying by sizeof(int)
        // Pointer arithmetic already scales by element size!
        int* p = ptr + (i * sizeof(int));  // BUG: Double scaling!
        // Should just be: ptr + i
        if (p < arr + 5) {
            printf("Value: %d\n", *p);
        }
    }

    return 0;
}
