#include <stdio.h>
#include <stdlib.h>

// Demonstrate the stack layout at program start
void show_stack_layout(int argc, char *argv[], char *envp[]) {
    printf("argc/argv/envp Stack Layout\n");
    printf("============================\n\n");

    printf("Stack layout at _start:\n");
    printf("  [argc]           = %d\n", argc);

    printf("\n  [argv pointers]\n");
    for (int i = 0; i < argc; i++) {
        printf("    argv[%d] @ %p -> \"%s\"\n", i, (void*)&argv[i], argv[i]);
    }
    printf("    argv[%d] @ %p -> NULL\n", argc, (void*)&argv[argc]);

    printf("\n  [envp pointers]\n");
    // BUG: Should start from 0, not 1
    for (int i = 1; i < 3 && envp[i] != NULL; i++) {
        printf("    envp[%d] @ %p -> \"%s\"\n", i, (void*)&envp[i], envp[i]);
    }
    printf("    ...\n");
}

void demonstrate_parsing(int argc, char *argv[]) {
    printf("\nParsing stack like _start does:\n");

    // Simulate what _start does
    // In reality: long *stack points to RSP
    // argc = *stack
    // argv = (char**)(stack + 1)
    // envp = argv + argc + 1

    printf("  1. Read argc from stack top\n");
    printf("  2. argv = stack + 1 (skip argc)\n");
    // BUG: Should be argc + 1, not argc
    printf("  3. envp = argv + argc (skip argv and NULL)\n");
    printf("  4. Parse until NULL terminator\n");
}

int main(int argc, char *argv[], char *envp[]) {
    show_stack_layout(argc, argv, envp);
    demonstrate_parsing(argc, argv);

    printf("\nThe kernel places this layout on the stack\n");
    printf("_start parses it before calling main()\n");

    return 0;
}
