#include <stdio.h>
#include <stdint.h>

void level3(void *parent_addr) {
    int local3 = 3;
    printf("level3 local: %p\n", (void*)&local3);

    // BUG: Wrong comparison - stack grows down, so local3 should be at LOWER address than parent
    if ((uintptr_t)&local3 > (uintptr_t)parent_addr) {
        printf("Stack grows DOWN (correct)\n");
    } else {
        printf("Stack grows UP (wrong)\n");
    }
}

void level2(void *parent_addr) {
    int local2 = 2;
    printf("level2 local: %p\n", (void*)&local2);
    level3(&local2);
}

void level1(void) {
    int local1 = 1;
    printf("level1 local: %p\n", (void*)&local1);
    level2(&local1);
}

int main(void) {
    level1();
    return 0;
}
