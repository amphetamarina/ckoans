#include <stdio.h>
#include "config.h"
#include "utils.h"

int main(void) {
    printf("Program version: %s\n", VERSION);
    printf("Result: %d\n", add(10, 20));
    return 0;
}
