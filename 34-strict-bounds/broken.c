#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int* end = arr + 5;  // OK: one-past-the-end pointer

    // Correct: iterate up to but not including end
    for (int* p = arr; p < end; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // BUG: Off-by-one error - dereferencing one-past-the-end
    for (int i = 0; i <= 5; i++) {  // BUG: Should be i < 5
        printf("%d ", arr[i]);  // BUG: arr[5] is out of bounds!
    }
    printf("\n");

    // BUG: Going way past the end
    int* way_past = arr + 10;  // BUG: UB - more than one-past-the-end
    // Dereferencing this is definitely UB
    // printf("%d\n", *way_past);  // BUG: Would crash or return garbage

    // BUG: Negative index
    // int* before = arr - 1;  // BUG: UB - before the beginning
    // printf("%d\n", *before);  // BUG: Out of bounds

    return 0;
}
