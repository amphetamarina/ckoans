#include <stdio.h>

int main(void) {
    int sum = 0;
    int i = 1;

    // BUG: Loop is incomplete
    loop_start:
        sum = sum + i;
        i = i + 1;
        // BUG: Missing conditional branch back to loop_start
        // Should be: if (i <= 10) goto loop_start;

    printf("Sum: %d\n", sum);
    return 0;
}
