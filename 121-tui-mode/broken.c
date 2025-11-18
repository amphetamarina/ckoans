#include <stdio.h>

void print_fibonacci(int n) {
    int a = 0, b = 1;

    printf("Fibonacci sequence (%d terms): ", n);

    // BUG: Should be i < n, not i <= n (prints n+1 terms)
    for (int i = 0; i <= n; i++) {
        if (i > 0) printf(", ");
        printf("%d", a);

        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void reverse_array(int arr[], int size) {
    // BUG: Should be i < size/2, not i <= size/2
    for (int i = 0; i <= size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int find_max(int arr[], int size) {
    int max = arr[0];
    // BUG: Should start at i = 1, not i = 0
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(void) {
    printf("TUI mode debugging:\n\n");

    print_fibonacci(5);

    int numbers[] = {1, 2, 3, 4, 5};
    printf("Original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    reverse_array(numbers, 5);
    printf("Reversed: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int values[] = {3, 7, 2, 9, 1, 5};
    int max = find_max(values, 6);
    printf("Max value: %d\n", max);

    return 0;
}
