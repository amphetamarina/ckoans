#include <stdio.h>

int main(void) {
    int a = 1;
    int b = 0;
    int x = 0;

    // BUG: Dangling else - ambiguous association
    // Does else belong to outer if or inner if?
    // C associates with nearest if (inner), but we want outer
    if (a)
        if (b)
            x = 1;
    else
        x = 2;

    printf("x = %d (should be 2, outer else)\n", x);

    // Another case
    int y = 0;
    int c = 1;
    int d = 0;

    // BUG: Another dangling else problem
    if (c)
        if (d)
            y = 10;
        else
            y = 20;  // This associates with inner if, not outer

    printf("y = %d\n", y);

    // BUG: We want the else to go with the outer if when d is false
    // Currently: c=1, d=0 → inner if's else executes → y=20
    // Desired: c=1, d=0 → inner if completes, outer has no else → y=0

    return 0;
}
