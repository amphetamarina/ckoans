#include <stdio.h>

// BUG: Wrong computation - will produce incorrect IR
int compute(int x, int y) {
    // BUG: Should be (x + y) * 2, but written as x + (y * 2)
    return x + y * 2;
}

// BUG: Missing optimization opportunity - redundant operations
int process(int n) {
    int temp = n + 0;  // BUG: Adding 0 is redundant
    temp = temp * 1;   // BUG: Multiplying by 1 is redundant
    temp = temp + 5;
    return temp;
}

int main(void) {
    int result1 = compute(10, 5);
    printf("Compute (10, 5): %d\n", result1);

    int result2 = process(15);
    printf("Process (15): %d\n", result2);

    // BUG: Dead code - never executed, but will appear in IR
    if (0) {
        printf("This never runs\n");
    }

    return 0;
}
