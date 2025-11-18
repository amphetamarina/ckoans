#include <stdio.h>
#include <stdint.h>

void print_frame_info(const char *func_name) {
    // Get current frame pointer (GCC builtin)
    void *fp = __builtin_frame_address(0);
    printf("%s frame pointer: %p\n", func_name, fp);
}

void level3(void) {
    print_frame_info("level3");
}

void level2(void) {
    print_frame_info("level2");
    level3();
}

void level1(void) {
    print_frame_info("level1");
    level2();
}

int main(void) {
    printf("Demonstrating frame unwinding:\n");
    print_frame_info("main");
    level1();

    // BUG: Incorrect depth - frame chain is: main -> level1 -> level2 -> level3 (depth 3)
    printf("\nCall depth from main: %d\n", 2);

    return 0;
}
