#include <stdio.h>

// Leaf function - can use red zone
int leaf_add(int a, int b) {
    int result = a + b;
    return result;
}

// Non-leaf function - calls other functions
int non_leaf_compute(int x) {
    int temp = x * 2;
    // BUG: This calls another function, so it's NOT a leaf function
    // But the comment incorrectly claims it can use red zone
    int result = leaf_add(temp, 10);
    return result;
}

int main(void) {
    int val1 = leaf_add(5, 3);
    printf("Leaf result: %d\n", val1);

    // BUG: Wrong argument - should pass 15 to get expected output
    int val2 = non_leaf_compute(10);
    printf("Non-leaf result: %d\n", val2);

    return 0;
}
