#include <stdio.h>

// BUG: Function declaration but no definition
// This will compile to .o but fail at link time
int compute_answer(void);

// BUG: Uncomment and implement this function to fix
/*
int compute_answer(void) {
    return 42;
}
*/

int main(void) {
    // This call references an undefined symbol
    int result = compute_answer();

    printf("The answer is: %d\n", result);

    return 0;
}
