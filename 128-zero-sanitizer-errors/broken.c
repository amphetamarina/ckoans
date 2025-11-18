#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divide(int a, int b) {
    // BUG: No check for division by zero (UBSan)
    return a / b;
}

void process_array(int *arr, int size) {
    // BUG: Off-by-one write (ASan)
    for (int i = 0; i <= size; i++) {
        arr[i] = i;
    }
}

char* allocate_string(const char *text) {
    int len = strlen(text);
    // BUG: Missing +1 for null terminator (ASan)
    char *result = malloc(len);
    strcpy(result, text);  // Overflow
    // BUG: Memory leak - never freed (LSan)
    return result;
}

int overflow_add(int a, int b) {
    // BUG: Integer overflow (UBSan)
    return a + b;
}

void use_freed_memory(void) {
    int *data = malloc(sizeof(int) * 3);
    data[0] = 42;
    free(data);
    // BUG: Use-after-free (ASan)
    printf("Value: %d\n", data[0]);
}

int main(void) {
    printf("Testing sanitizer coverage:\n\n");

    // UBSan: division by zero
    int result1 = divide(10, 0);
    printf("10 / 0 = %d\n", result1);

    // ASan: heap buffer overflow
    int *buffer = malloc(5 * sizeof(int));
    process_array(buffer, 5);
    free(buffer);

    // LSan: memory leak
    char *msg = allocate_string("Hello");
    printf("Message: %s\n", msg);
    // BUG: Should free msg

    // UBSan: integer overflow
    int result2 = overflow_add(2147483647, 1);
    printf("Overflow result: %d\n", result2);

    // ASan: use-after-free
    use_freed_memory();

    printf("\nAll tests completed\n");
    return 0;
}
