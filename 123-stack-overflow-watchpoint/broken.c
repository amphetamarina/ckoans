#include <stdio.h>

int fibonacci(int n) {
    // BUG: Missing base case for n == 0
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int countdown(int n) {
    printf("%d ", n);
    // BUG: Should have base case if (n <= 0) return;
    return countdown(n - 1);
}

int sum_to_n(int n) {
    // BUG: Base case checks n == 1, should be n <= 0
    if (n == 1) return 1;
    return n + sum_to_n(n - 1);
}

void mutual_recursion_a(int n);
void mutual_recursion_b(int n);

void mutual_recursion_a(int n) {
    if (n > 0) {
        printf("A%d ", n);
        mutual_recursion_b(n - 1);
    }
}

void mutual_recursion_b(int n) {
    // BUG: Missing base case check
    printf("B%d ", n);
    mutual_recursion_a(n - 1);
}

int main(void) {
    printf("Stack overflow detection:\n\n");

    // This will cause stack overflow due to missing base case
    printf("Fibonacci(5) = %d\n", fibonacci(5));

    // This will cause infinite recursion
    // countdown(5);

    // This will overflow on negative input
    printf("Sum to -5 = %d\n", sum_to_n(-5));

    // Mutual recursion bug
    printf("\nMutual recursion: ");
    mutual_recursion_a(3);
    printf("\n");

    return 0;
}
