#include <stdio.h>
#include "config.h"

extern int module1_func(void);
extern int module2_func(void);

int main(void) {
    printf("Version: %s\n", VERSION);
    printf("Module1: %d\n", module1_func());
    printf("Module2: %d\n", module2_func());
    return 0;
}
