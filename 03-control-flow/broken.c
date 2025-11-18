#include <stdio.h>

// BUG: Function doesn't return a value properly
int add(int x, int y) {
    int sum = x + y;
    // BUG: Missing return statement - undefined behavior!
}

int main(void) {
    int result = add(10, 20);
    printf("Sum: %d\n", result);
    return 0;
}
