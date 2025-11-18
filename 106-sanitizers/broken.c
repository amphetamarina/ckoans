#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BUG: Buffer overflow - writes past allocated memory
void buffer_overflow_bug(void) {
    char *buf = malloc(10);
    strcpy(buf, "This string is way too long for the buffer!");
    printf("%s\n", buf);
    free(buf);
}

// BUG: Use after free
void use_after_free_bug(void) {
    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    free(ptr);
    printf("Value: %d\n", *ptr);  // BUG: reading freed memory
}

// BUG: Signed integer overflow (undefined behavior)
int integer_overflow_bug(void) {
    int x = 2147483647;
    return x + 1;  // BUG: signed overflow is UB
}

// BUG: Null pointer dereference
void null_deref_bug(void) {
    int *ptr = NULL;
    *ptr = 42;  // BUG: dereferencing NULL
}

int main(void) {
    printf("Starting tests...\n");

    // BUG: This will trigger ASan
    buffer_overflow_bug();

    // BUG: This will trigger ASan
    use_after_free_bug();

    // BUG: This will trigger UBSan
    printf("Overflow result: %d\n", integer_overflow_bug());

    // BUG: This will trigger ASan
    null_deref_bug();

    printf("All tests passed!\n");
    return 0;
}
