#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(void) {
    printf("=== Environment Variables Demo ===\n\n");

    // Set a custom environment variable
    // BUG: setenv takes 3 arguments: name, value, overwrite
    setenv("CUSTOM_VAR", "custom_value");

    // Retrieve and print it
    // BUG: getenv returns the value, not the whole NAME=value string
    char *custom = getenv("CUSTOM_VAR");
    if (custom) {
        printf("CUSTOM_VAR=%s\n", custom);
    }

    // Check for MY_VAR passed from shell
    // BUG: Wrong function - getenv returns value, not full string
    char *my_var = getenv("MY_VAR");
    if (my_var) {
        printf("MY_VAR is set to: %s\n", my_var);
    } else {
        printf("MY_VAR is not set\n");
    }

    // Print first 3 environment variables using environ
    printf("\nFirst 3 environment variables:\n");
    for (int i = 0; i < 3 && environ[i] != NULL; i++) {
        // BUG: Trying to print environ[i] as integer instead of string
        printf("%d: %d\n", i + 1, environ[i]);
    }

    return 0;
}
