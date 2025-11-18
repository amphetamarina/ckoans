#include <stdio.h>

int buggy_calc(int x, int y, int z) {
    int temp1 = x + y;
    int temp2 = y + z;
    // BUG: Should multiply temp1 * temp2, not add
    int result = temp1 + temp2;

    printf("Debug: x=%d y=%d z=%d temp1=%d temp2=%d result=%d\n",
           x, y, z, temp1, temp2, result);

    return result;
}

void caller(void) {
    int a = 3;
    int b = 4;
    int c = 5;

    printf("Calling buggy_calc(%d, %d, %d)\n", a, b, c);
    int answer = buggy_calc(a, b, c);
    printf("Answer: %d\n", answer);
}

int main(void) {
    printf("=== Stack Frame Inspection Demo ===\n");
    caller();
    return 0;
}
