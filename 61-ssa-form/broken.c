#include <stdio.h>

int compute(int a, int b) {
    // BUG: Redundant intermediate assignments create extra SSA versions
    int x = a;
    x = x + 1;
    x = x + 2;
    x = x + 3;

    int y = b;
    y = y * 2;
    y = y + 1;

    // BUG: Could be simplified to reduce SSA versions
    int result = x + y;
    result = result;  // BUG: Redundant assignment

    return result;
}

int conditional_compute(int n) {
    int value;

    // This will create a phi function in SSA
    if (n > 10) {
        // BUG: Unnecessary intermediate variable
        int temp = n + 5;
        value = temp;
    } else {
        // BUG: Unnecessary intermediate variable
        int temp = n - 3;
        value = temp;
    }

    // BUG: Another redundant assignment
    int final = value;
    return final;
}

int main(void) {
    int result1 = compute(5, 10);
    printf("Compute: %d\n", result1);

    int result2 = conditional_compute(12);
    printf("Conditional (12): %d\n", result2);

    int result3 = conditional_compute(8);
    printf("Conditional (8): %d\n", result3);

    return 0;
}
