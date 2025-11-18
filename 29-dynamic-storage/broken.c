#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_message(void) {
    // Allocate memory on the heap
    char* msg = malloc(50);
    if (!msg) {
        return NULL;
    }

    strcpy(msg, "Dynamic memory persists beyond function scope");
    return msg;  // Memory persists even after function returns
}

int main(void) {
    char* message = create_message();

    if (message) {
        printf("%s\n", message);
        // BUG: Missing free(message) - memory leak!
    }

    // Demonstrate that dynamic allocation persists
    int* numbers = malloc(5 * sizeof(int));
    if (numbers) {
        for (int i = 0; i < 5; i++) {
            numbers[i] = i * 10;
        }
        printf("Numbers: %d %d %d %d %d\n",
               numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
        // BUG: Missing free(numbers) - another memory leak!
    }

    return 0;
}
