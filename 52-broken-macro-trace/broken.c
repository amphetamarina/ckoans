#include <stdio.h>

// BUG: Missing outer parentheses - will fail with multiplication
#define CIRCLE_AREA(r) 3.14159 * r * r

// BUG: Missing parentheses around 'n' - fails with expressions
#define FACTORIAL_APPROX(n) n * (n - 1) / 2

// BUG: Wrong formula - should be (a*a + b*b)
#define SUM_OF_SQUARES(a, b) a * a + b * b

// BUG: Missing parentheses around parameters and result
#define RECTANGLE_AREA(w, h) w * h

int main(void) {
    // BUG: CIRCLE_AREA(2 + 1) expands to 3.14159 * 2 + 1 * 2 + 1
    double area = CIRCLE_AREA(2 + 1);
    printf("Circle area (r=3): %.2f\n", area);

    // BUG: FACTORIAL_APPROX(4 + 1) expands to 4 + 1 * (4 + 1 - 1) / 2
    int fact = FACTORIAL_APPROX(4 + 1);
    printf("Factorial approx (5): %d\n", fact);

    // BUG: SUM_OF_SQUARES(2, 3) needs parentheses for correct precedence
    // When used in division: SUM_OF_SQUARES(2,3) / 2
    int sum = SUM_OF_SQUARES(2, 3) / 2;
    printf("Sum of squares (2,3) / 2: %d\n", sum);

    // BUG: RECTANGLE_AREA(3+1, 4+2) expands to 3+1 * 4+2
    int rect = RECTANGLE_AREA(3 + 1, 4 + 2);
    printf("Rectangle area (4x6): %d\n", rect);

    return 0;
}
