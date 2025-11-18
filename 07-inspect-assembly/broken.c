#include <stdio.h>

int main(void) {
    int x = 5;
    int y = x + 3;  // BUG: Should be x + 10
    printf("%d\n", y);
    return 0;
}
