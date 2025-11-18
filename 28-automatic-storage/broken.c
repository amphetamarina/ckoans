#include <stdio.h>

void show_automatic_lifetime(void) {
    // BUG: Uninitialized automatic variable contains garbage
    int automatic_var;

    printf("Automatic variable: %d\n", automatic_var);
}

int main(void) {
    // BUG: Uninitialized variable - contains garbage value
    int sum;

    int a = 10;
    int b = 20;

    // BUG: Using uninitialized sum
    sum = sum + a + b;

    printf("Sum: %d\n", sum);
    show_automatic_lifetime();

    return 0;
}
