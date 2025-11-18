#include <stdio.h>
#include <limits.h>

int add_with_overflow(int a, int b) {
    // BUG: No overflow check
    return a + b;
}

int multiply_overflow(int a, int b) {
    // BUG: No overflow check
    return a * b;
}

int calculate_buffer_size(int count, int item_size) {
    // BUG: Multiplication can overflow
    int total = count * item_size;

    if (total <= 0) {
        // BUG: This check is too late, overflow already happened
        printf("Invalid size\n");
        return 0;
    }

    return total;
}

int negate_overflow(int n) {
    // BUG: Negating INT_MIN causes overflow
    return -n;
}

int main(void) {
    printf("Integer overflow detection:\n\n");

    // Test 1: Addition overflow
    int max = INT_MAX;
    // BUG: This will overflow
    int sum = add_with_overflow(max, 1);
    printf("INT_MAX + 1 = %d\n", sum);

    // Test 2: Multiplication overflow
    // BUG: This will overflow
    int product = multiply_overflow(100000, 100000);
    printf("100000 * 100000 = %d\n", product);

    // Test 3: Buffer size calculation
    // BUG: Large count causes overflow
    int size = calculate_buffer_size(1000000000, 10);
    printf("Buffer size: %d\n", size);

    // Test 4: Negation overflow
    // BUG: -INT_MIN overflows
    int negated = negate_overflow(INT_MIN);
    printf("Negated INT_MIN: %d\n", negated);

    return 0;
}
