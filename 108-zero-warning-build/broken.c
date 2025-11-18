#include <stdio.h>
#include <string.h>

// BUG: K&R style function declaration (no prototype)
int old_style_function(x, y)
    int x;
    int y;
{
    return x + y;
}

// BUG: Function not used - should be static or removed
void unused_helper(void) {
    printf("This is never called\n");
}

// BUG: Shadow warning - parameter shadows global
int global_var = 10;

int shadow_bug(int global_var) {  // BUG: shadows global
    return global_var * 2;
}

// BUG: Implicit conversion warnings
void conversion_bugs(void) {
    // BUG: Double to int conversion
    double pi = 3.14159;
    int truncated = pi;

    // BUG: Signed to unsigned conversion
    int negative = -1;
    unsigned int unsigned_val = negative;

    printf("Truncated: %d, Unsigned: %u\n", truncated, unsigned_val);
}

// BUG: Format string vulnerability
void format_bug(const char *user_input) {
    // BUG: user_input used as format string
    printf(user_input);
}

// BUG: Unused parameter
void unused_param_bug(int used, int unused) {
    printf("Used: %d\n", used);
}

// BUG: Missing const for read-only pointer
void missing_const(char *str) {
    printf("String: %s\n", str);
}

int main(void) {
    printf("Testing zero-warning fixes:\n");

    // BUG: calls function with warnings
    printf("Old style: %d\n", old_style_function(5, 3));

    printf("Shadow: %d\n", shadow_bug(20));

    conversion_bugs();

    format_bug("Safe string\n");

    unused_param_bug(42, 0);

    missing_const("Hello");

    return 0;
}
