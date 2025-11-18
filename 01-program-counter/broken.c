#include <stdio.h>

int main(void) {
    int i = 1;

    // BUG: Incorrect loop condition causes wrong behavior
    while (i < 5) {
        printf("%d\n", i);
        // BUG: Missing increment - PC will loop forever at same instruction
    }

    return 0;
}
