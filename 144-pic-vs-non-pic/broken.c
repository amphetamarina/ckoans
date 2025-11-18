#include <stdio.h>

// Global variable that will be accessed differently in PIC vs non-PIC
int global_counter = 0;

// Function that accesses global data
void increment_counter(void) {
    global_counter++;
}

int get_counter(void) {
    return global_counter;
}

// Demonstrate address calculation
void show_addressing(void) {
    // PIC code uses GOT for global variable access
    // Non-PIC code uses absolute addresses

    printf("Counter address: %p\n", (void*)&global_counter);
    printf("Function address: %p\n", (void*)&increment_counter);
}

int main(void) {
    printf("PIC vs non-PIC demonstration\n");

    // Increment counter several times
    for (int i = 0; i < 5; i++) {
        increment_counter();
    }

    // BUG: Wrong counter value
    int counter = get_counter() + 2;
    printf("Counter value: %d\n", counter);

    show_addressing();

    // PIC code can be loaded at any address
    printf("PIC enables ASLR and code sharing\n");

    return 0;
}
