#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_buffer(int *buffer, int size) {
    // BUG: Should be i < size, not i <= size (writes one past end)
    for (int i = 0; i <= size; i++) {
        buffer[i] = i * 10;
    }
}

void copy_string(const char *src) {
    int len = strlen(src);
    char *dest = malloc(len);  // BUG: Should be len + 1 for null terminator

    strcpy(dest, src);  // BUG: This overflows by 1 byte
    printf("Copied: %s\n", dest);

    free(dest);
}

void read_out_of_bounds(void) {
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("Values: ");
    // BUG: Should be i < 5, not i < 6 (reads past end)
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main(void) {
    printf("Heap out-of-bounds detection:\n\n");

    int *buffer = malloc(10 * sizeof(int));
    process_buffer(buffer, 10);

    printf("Buffer values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
    free(buffer);

    copy_string("Hello");

    read_out_of_bounds();

    return 0;
}
