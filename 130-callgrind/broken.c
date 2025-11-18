#include <stdio.h>

// BUG: Inefficient - recalculates same values repeatedly
int fibonacci_slow(int n) {
    if (n <= 1) return n;
    return fibonacci_slow(n - 1) + fibonacci_slow(n - 2);
}

// Fixed version using memoization (commented out)
// int fib_memo[100] = {0};
// int fibonacci_fast(int n) {
//     if (n <= 1) return n;
//     if (fib_memo[n] != 0) return fib_memo[n];
//     fib_memo[n] = fibonacci_fast(n - 1) + fibonacci_fast(n - 2);
//     return fib_memo[n];
// }

// BUG: O(n^2) algorithm when O(n) is possible
int sum_to_n_slow(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        // BUG: Redundantly calculating sum multiple times
        for (int j = 1; j <= i; j++) {
            sum++;
        }
    }
    return sum;
}

// Fixed version: O(n) algorithm
// int sum_to_n_fast(int n) {
//     return n * (n + 1) / 2;
// }

int is_prime_slow(int n) {
    if (n < 2) return 0;
    // BUG: Checking all numbers up to n instead of sqrt(n)
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    printf("Callgrind profiling demonstration:\n\n");

    // This will show up as hot in Callgrind
    printf("Fibonacci(30) = %d\n", fibonacci_slow(30));

    // This will also show up as inefficient
    printf("Sum to 1000 = %d\n", sum_to_n_slow(1000));

    // Count primes up to 5000 (slow)
    int prime_count = 0;
    for (int i = 2; i < 5000; i++) {
        if (is_prime_slow(i)) {
            prime_count++;
        }
    }
    printf("Primes below 5000: %d\n", prime_count);

    return 0;
}
