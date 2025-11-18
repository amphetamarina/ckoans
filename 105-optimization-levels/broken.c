#include <stdio.h>

// BUG: Undefined behavior - modifying and reading same variable without sequence point
int buggy_increment(int x) {
    // At -O0 this may work, but at -O2 the optimizer assumes no UB
    return x++ + x++;
}

// BUG: Infinite loop that optimizer can remove due to UB
int count_up(void) {
    // Signed overflow is UB - optimizer may assume this never overflows
    int i = 2147483640;
    int count = 0;
    while (i > 0) {
        i++;
        count++;
        if (count >= 10) break;
    }
    return count;
}

// BUG: Uninitialized variable - may be zero at -O0, garbage at -O2
int use_uninitialized(void) {
    int x;
    if (x == 0) {
        x = 10;
    } else {
        x = 20;
    }
    return x;
}

int main(void) {
    // BUG: buggy_increment has UB - fix to return well-defined value
    printf("Increment: %d\n", buggy_increment(5));

    // BUG: count_up has UB - fix to return 10
    printf("Count: %d\n", count_up());

    // BUG: use_uninitialized has UB - fix to return 10
    printf("Value: %d\n", use_uninitialized());

    return 0;
}
