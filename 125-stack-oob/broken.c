#include <stdio.h>
#include <string.h>

void fill_buffer(void) {
    int marker1 = 0xAAAA;
    char buffer[8];
    int marker2 = 0xBBBB;

    printf("Before: marker1=%x, marker2=%x\n", marker1, marker2);

    // BUG: Should be i < 8, not i < 10 (overflows buffer)
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'A' + i;
    }

    printf("After: marker1=%x, marker2=%x\n", marker1, marker2);
}

void string_overflow(void) {
    char dest[5];
    // BUG: "Hello" is 6 bytes with null terminator, dest is only 5 bytes
    strcpy(dest, "Hello");
    printf("String: %s\n", dest);
}

void array_write_overflow(void) {
    int arr[5] = {0};
    int sentinel = 42;

    printf("Before overflow: sentinel = %d\n", sentinel);

    // BUG: Should be i < 5, not i <= 5
    for (int i = 0; i <= 5; i++) {
        arr[i] = i * 10;
    }

    printf("After overflow: sentinel = %d\n", sentinel);

    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    printf("Stack out-of-bounds detection:\n\n");

    fill_buffer();
    printf("\n");

    string_overflow();
    printf("\n");

    array_write_overflow();

    return 0;
}
