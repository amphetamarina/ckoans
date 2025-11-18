#include <stdio.h>
#include <stdlib.h>

// Simulate the C runtime initialization steps
void simulate_crt0(void) {
    printf("C Runtime Initialization (_start)\n");
    printf("==================================\n\n");

    printf("Step 1: Kernel loads program and jumps to _start\n");
    printf("Step 2: _start sets up the stack\n");
    printf("Step 3: Initialize .bss section (zero-fill)\n");
    // BUG: Step 4 should be before step 5
    printf("Step 4: Call main()\n");
    printf("Step 5: Parse argc, argv, envp from stack\n");
    printf("Step 6: Call global constructors\n");
}

void simulate_main_execution(void) {
    printf("\nMain Function Execution\n");
    printf("=======================\n");
    printf("Your main() function runs here\n");
    printf("Can use libc functions: printf, malloc, etc.\n");
}

void simulate_exit(int code) {
    printf("\nProgram Exit\n");
    printf("============\n");
    printf("Step 1: main() returns with code: %d\n", code);
    printf("Step 2: C runtime calls exit(%d)\n", code);
    printf("Step 3: Run atexit handlers\n");
    printf("Step 4: Call global destructors\n");
    printf("Step 5: Flush stdio buffers\n");
    printf("Step 6: Invoke _exit syscall\n");
}

int main(void) {
    printf("_start vs main\n");
    printf("==============\n\n");

    simulate_crt0();
    simulate_main_execution();

    // BUG: Exit code should be 0, not 1
    int exit_code = 1;
    simulate_exit(exit_code);

    printf("\n_start is the real entry point, not main!\n");

    return 0;
}
