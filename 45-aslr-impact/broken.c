#include <stdio.h>
#include <stdlib.h>

int global_var = 42;

void function_in_text(void) {
    printf("Function address randomized by ASLR\n");
}

int main(void) {
    int stack_var = 42;
    int* heap_var = malloc(sizeof(int));
    *heap_var = 42;

    printf("=== ASLR Impact ===\n");
    printf("\n");

    printf("Run this program multiple times.\n");
    printf("With ASLR enabled, addresses will change each time.\n");
    printf("\n");

    printf("ASLR makes these addresses unpredictable.\n");
    printf("This prevents attackers from hardcoding addresses.\n");
    printf("\n");

    printf("Check ASLR status:\n");
    printf("  cat /proc/sys/kernel/randomize_va_space\n");
    printf("  (2 = full ASLR, 1 = partial, 0 = disabled)\n");

    free(heap_var);
    return 0;
}
