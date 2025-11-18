#include <stdio.h>

// BUG: Missing semicolon after function declaration
int add(int a, int b)

// BUG: Function body without proper header
{
    return a + b;
}

// BUG: Invalid syntax - missing type
multiply(int a, int b) {
    return a * b;
}

int main(void) {
    // BUG: Missing semicolon
    int x = 10
    int y = 20;

    // BUG: Expression where statement expected
    int result = add(x, y)
    printf("Add: %d\n", result);

    // BUG: Missing closing brace for if statement
    if (x > 5) {
        printf("x is large\n");
    // Missing }

    // BUG: Statement without proper termination
    int product = multiply(x, y)
    printf("Multiply: %d\n", product)

    // BUG: Extra semicolon after function definition attempt
    // This creates an empty statement where declaration expected

    return 0;
}
// BUG: Missing closing brace for main
