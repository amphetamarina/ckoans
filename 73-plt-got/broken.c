#include <stdio.h>
#include <stdlib.h>

// All these library functions use PLT/GOT mechanism
// Call to printf@plt -> looks up in GOT -> jumps to actual printf in libc.so

void demonstrate_plt_got(void) {
    // First call to printf triggers lazy binding:
    // 1. Call printf@plt
    // 2. PLT stub calls dynamic linker
    // 3. Dynamic linker resolves printf address
    // 4. Updates GOT entry
    // 5. Jumps to actual printf

    // BUG: Should say "First", not "Second"
    printf("Second call - triggers lazy binding\n");

    // Second call uses already-resolved GOT entry
    // BUG: Should say "Second", not "First"
    printf("First call - uses cached GOT entry\n");
}

int main(void) {
    // Each of these external functions has:
    // - Entry in .plt section (executable code stub)
    // - Entry in .got.plt section (function pointer, initially points to resolver)

    int value = 42;

    // BUG: Should be value (42), not value + 1
    printf("Value: %d\n", value + 1);

    demonstrate_plt_got();

    return 0;
}
