#include <stdio.h>

int main(void) {
    // BUG: Invalid identifier - starts with digit
    int 2count = 10;

    // BUG: Invalid character literal - too many characters
    char letter = 'ab';

    // BUG: Unclosed string literal
    const char *msg = "Hello world;

    // BUG: Invalid hexadecimal constant (missing digits after 0x)
    int hex = 0x;

    // BUG: Invalid operator - space in between
    int result = 5 + + 3;

    printf("Count: %d\n", 2count);
    printf("Letter: %c\n", letter);
    printf("Message: %s\n", msg);
    printf("Hex: %d\n", hex);
    printf("Result: %d\n", result);

    return 0;
}
