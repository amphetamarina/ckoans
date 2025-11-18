#include <stdio.h>

int add_three(int a, int b, int c) {
    int sum = a + b + c;
    // BUG: Wrong return value
    return a + b;  // Should return sum
}

int main(void) {
    int result = add_three(10, 20, 30);
    printf("%d\n", result);
    return 0;
}
