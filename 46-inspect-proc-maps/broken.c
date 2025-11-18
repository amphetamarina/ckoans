#include <stdio.h>
#include <stdlib.h>

int global_var = 42;

int main(void) {
    int stack_var = 42;
    int* heap_var = malloc(sizeof(int));
    *heap_var = 42;

    printf("=== /proc/self/maps ===\n");
    printf("\n");

    printf("This process's memory layout:\n");
    printf("\n");

    // Students should uncomment this to view the memory map
    /*
    FILE* maps = fopen("/proc/self/maps", "r");
    if (maps) {
        char line[256];
        while (fgets(line, sizeof(line), maps)) {
            printf("%s", line);
        }
        fclose(maps);
    }
    */

    printf("\n");
    printf("Legend:\n");
    printf("  r = readable\n");
    printf("  w = writable\n");
    printf("  x = executable\n");
    printf("  p = private (copy-on-write)\n");
    printf("  s = shared\n");
    printf("\n");

    printf("Look for:\n");
    printf("  r-xp regions = code (.text)\n");
    printf("  rw-p regions = data (.data, .bss)\n");
    printf("  [heap] = heap memory\n");
    printf("  [stack] = stack memory\n");
    printf("  lib*.so = shared libraries\n");

    free(heap_var);
    return 0;
}
