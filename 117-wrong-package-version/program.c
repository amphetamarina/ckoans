#include <stdio.h>

// Simulating weblib API
// The actual API works fine with version 2.5
void weblib_init(void) {
    printf("Weblib initialized\n");
}

int main(void) {
    weblib_init();
    printf("Program running successfully\n");
    return 0;
}
