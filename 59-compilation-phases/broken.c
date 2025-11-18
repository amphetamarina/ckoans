#include <stdio.h>

// BUG: Macro with wrong expansion - preprocessor phase
#define MESSAGE "Hello World"
#define VALUE 42

// BUG: Syntax error - will be caught in compilation phase
int calculate(int x) {
    // Missing return statement - caught in compilation
    int result = x * 2;
    result;  // BUG: Not a return statement
}

// Forward declaration - needed for linking phase
// BUG: If missing, linker will complain
extern int helper(int n);

int helper(int n) {
    return n + 10;
}

int main(void) {
    printf("Message: %s\n", MESSAGE);
    printf("Value: %d\n", VALUE);

    // BUG: calculate doesn't return properly
    int x = calculate(5);
    printf("Calculate: %d\n", x);

    int y = helper(7);
    printf("Helper: %d\n", y);

    return 0;
}
