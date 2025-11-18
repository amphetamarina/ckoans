#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void demonstrate_allocations(void) {
    // Stack allocation
    int stack_var = 42;

    // Heap allocation
    int* heap_var = malloc(sizeof(int));
    *heap_var = 42;

    uintptr_t stack_addr = (uintptr_t)&stack_var;
    uintptr_t heap_addr = (uintptr_t)heap_var;

    if (stack_addr > heap_addr) {
        printf("Stack is at higher addresses than heap\n");
    }

    free(heap_var);
}

// BUG: Large stack allocation can cause overflow
void potential_stack_overflow(void) {
    // BUG: This is too large for stack (8 MB limit)
    // char huge_array[10 * 1024 * 1024];  // 10 MB - would overflow!

    // Correct: allocate large data on heap
    char* huge_array = malloc(10 * 1024 * 1024);
    if (huge_array) {
        free(huge_array);
    }
}

int main(void) {
    printf("=== Heap and Stack Growth ===\n");
    printf("\n");

    printf("Stack growth demonstration:\n");
    demonstrate_allocations();

    potential_stack_overflow();

    printf("\n");
    printf("Check stack size: ulimit -s\n");

    return 0;
}
