#include <stdio.h>

// .bss - uninitialized global (zero-initialized)
int global_uninit;

// .data - initialized global
int global_init = 42;

// .bss - uninitialized static (zero-initialized)
static int static_uninit;

// .data - initialized static
static int static_init = 100;

// .rodata - string literal (read-only data)
const char* message = "Hello from .rodata";

void function_in_text(void) {  // Code goes in .text
    // BUG: Local variables go on STACK, not in .data or .bss!
    int local_var = 50;

    // BUG: Static local goes in .data (initialized) or .bss (uninitialized)
    // Not on stack like regular locals!
    static int local_static_uninit;  // .bss
    static int local_static_init = 200;  // .data

    local_static_uninit++;
    local_static_init++;

    printf("Local: %d\n", local_var);
    printf("Local static uninit: %d\n", local_static_uninit);
    printf("Local static init: %d\n", local_static_init);
}

int main(void) {
    printf("=== .text / .data / .bss ===\n");
    printf("\n");

    printf(".data (initialized):\n");
    printf("  global_init = %d\n", global_init);
    printf("  static_init = %d\n", static_init);
    printf("\n");

    printf(".bss (uninitialized, zero-initialized):\n");
    printf("  global_uninit = %d\n", global_uninit);
    printf("  static_uninit = %d\n", static_uninit);
    printf("\n");

    printf(".rodata (read-only):\n");
    printf("  message = %s\n", message);
    printf("\n");

    printf(".text (code):\n");
    function_in_text();

    printf("\n");
    printf("Run 'size broken' to see section sizes\n");

    return 0;
}
