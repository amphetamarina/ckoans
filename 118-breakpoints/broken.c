#include <stdio.h>

int calculate_sum(int n) {
    int sum = 0;
    // BUG: Should start at i=1, not i=0
    for (int i = 0; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int factorial(int n) {
    if (n <= 1) return 1;
    // BUG: Should multiply by n, not n-1
    return n * factorial(n - 1);
}

int count_evens(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        // BUG: Should be arr[i] % 2 == 0
        if (arr[i] % 2 == 1) {
            count++;
        }
    }
    return count;
}

int main(void) {
    printf("Testing breakpoint debugging:\n\n");

    // Test 1: Sum from 1 to 10
    int sum = calculate_sum(10);
    printf("Sum(1..10) = %d\n", sum);

    // Test 2: Factorial of 5
    int fact = factorial(5);
    printf("Factorial(5) = %d\n", fact);

    // Test 3: Count even numbers
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int evens = count_evens(numbers, 10);
    printf("Even count in [1..10] = %d\n", evens);

    return 0;
}
