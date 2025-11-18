#include <stdio.h>

// Internal helper function - should be hidden
// BUG: Missing visibility attribute
int internal_helper(int x) {
    return x * 2;
}

// Internal state - should be hidden
// BUG: Missing visibility attribute
static int internal_state = 0;

// Public API - should be visible
__attribute__((visibility("default")))
int public_function(int value) {
    internal_state += value;
    return internal_helper(internal_state);
}

// Another public API
__attribute__((visibility("default")))
int get_state(void) {
    // BUG: Should return internal_state, not internal_state + 1
    return internal_state + 1;
}

// Protected symbol - visible but can't be overridden
__attribute__((visibility("protected")))
int protected_function(void) {
    return 42;
}

int main(void) {
    printf("Symbol Visibility Test\n");

    // Use public API
    public_function(10);
    public_function(20);

    int state = get_state();
    printf("State: %d\n", state);

    int prot = protected_function();
    printf("Protected: %d\n", prot);

    printf("Hidden symbols reduce symbol pollution\n");

    return 0;
}
