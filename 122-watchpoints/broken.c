#include <stdio.h>

void fill_array(int arr[], int size, int value) {
    // BUG: Should be i < size, not i <= size (writes past end)
    for (int i = 0; i <= size; i++) {
        arr[i] = value;
    }
}

void increment_values(int *values, int count) {
    // BUG: Should be i < count, not i <= count
    for (int i = 0; i <= count; i++) {
        values[i]++;
    }
}

int main(void) {
    printf("Watchpoint debugging:\n\n");

    int target = 42;
    int buffer[5] = {0};

    printf("Initial target value: %d\n", target);

    // BUG: This will write past buffer and corrupt 'target'
    // (if target is allocated just after buffer on stack)
    fill_array(buffer, 5, 10);

    printf("After fill_array, target value: %d\n", target);

    int counter = 100;
    int data[3] = {1, 2, 3};

    printf("Initial counter: %d\n", counter);

    // BUG: This may also corrupt 'counter'
    increment_values(data, 3);

    printf("After increment, counter: %d\n", counter);

    printf("\nBuffer contents: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    printf("Final target: %d\n", target);
    printf("Final counter: %d\n", counter);

    return 0;
}
