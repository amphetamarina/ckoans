#include <stdio.h>

// BUG: Inefficient - could be optimized to constant
int calculate_constant(void) {
    int a = 5;
    int b = 10;
    int c = a + b;  // BUG: Computed at runtime, could be compile-time
    return c * 2;   // BUG: Result is always 30
}

// BUG: Function does nothing useful but generates machine code
int identity(int x) {
    int temp = x;
    return temp;  // BUG: Just returns input, extra assignment
}

// BUG: Inefficient stack usage
int add_three(int a, int b, int c) {
    // BUG: Unnecessary intermediate variables
    int sum1 = a + b;
    int sum2 = sum1 + c;
    int result = sum2;
    return result;
}

int main(void) {
    int x = calculate_constant();
    printf("Constant: %d\n", x);

    int y = identity(42);
    printf("Identity: %d\n", y);

    int z = add_three(10, 20, 30);
    printf("Sum: %d\n", z);

    return 0;
}
