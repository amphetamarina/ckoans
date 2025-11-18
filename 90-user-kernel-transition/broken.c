#include <stdio.h>
#include <unistd.h>
#include <string.h>

void inefficient_write(void) {
    const char *message = "Hello, World!\n";

    // BUG: Writing one character at a time - each causes a syscall!
    // This is extremely inefficient
    for (size_t i = 0; i < strlen(message); i++) {
        write(STDOUT_FILENO, &message[i], 1);
    }
}

void efficient_write(void) {
    const char *message = "Hello, World!\n";

    // Correct: Single syscall for entire message
    // BUG: But we're calling inefficient_write() in main
    write(STDOUT_FILENO, message, strlen(message));
}

int main(void) {
    printf("=== User to Kernel Transition Demo ===\n\n");

    printf("Writing message (check syscall count with strace):\n");

    // BUG: Calling inefficient version - should call efficient_write()
    inefficient_write();

    printf("\nEach write() call causes a mode switch to kernel!\n");
    printf("Use 'strace -c ./broken' to see syscall statistics\n");

    return 0;
}
