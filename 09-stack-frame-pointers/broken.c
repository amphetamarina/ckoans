#include <stdio.h>

void func(int x) {
    int local = x * 2;
    // BUG: Wrong local variable used
    printf("Value: %d\n", x);  // Should print local, not x
}

int main(void) {
    func(10);
    return 0;
}
