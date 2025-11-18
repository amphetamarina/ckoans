#include <stdio.h>

int multiply(int a, int b) {
    int result = 0;
    for (int i = 0; i < b; i++) {
        result += a;
    }
    return result;
}

int square(int n) {
    // BUG: Should be multiply(n, n), not multiply(n, n-1)
    return multiply(n, n - 1);
}

int sum_of_squares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += square(i);
    }
    return sum;
}

int power(int base, int exp) {
    if (exp == 0) return 1;
    // BUG: Should be base * power(base, exp - 1)
    return power(base, exp - 1);
}

int main(void) {
    printf("Stepping through nested calls:\n\n");

    int sq = square(5);
    printf("Square of 5 = %d\n", sq);

    int sum_sq = sum_of_squares(4);
    printf("Sum of squares 1..4 = %d\n", sum_sq);

    int pow_result = power(2, 3);
    printf("2^3 = %d\n", pow_result);

    return 0;
}
