#include <stdio.h>

// BUG: This should be visible to other compilation units
// but 'static' makes it local-only (not in global symbol table)
static int compute_sum(int a, int b) {
    return a + b;
}

int global_value = 42;

int main(void) {
    int result = compute_sum(10, 20);
    printf("Sum: %d\n", result);
    printf("Global: %d\n", global_value);
    return 0;
}
