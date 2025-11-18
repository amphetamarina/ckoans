#include <stdio.h>

int main(void) {
    // BUG: Excessive intermediate variables create register pressure
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    int f = 6, g = 7, h = 8, i = 9, j = 10;
    int k = 11, l = 12, m = 13, n = 14, o = 15;

    // BUG: Overly complex expression
    int result = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o;

    // Actually, we only need this:
    // int result = 1+2+3+4+5+6+7+8+9+10+11+12+13+14+15;
    // Or better yet: int result = 120;

    printf("Result: %d\n", result);
    return 0;
}
