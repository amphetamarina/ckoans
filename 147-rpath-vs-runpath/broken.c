#include <stdio.h>
#include <stdlib.h>

void demonstrate_rpath(void) {
    printf("RPATH:\n");
    printf("  - Embedded at link time\n");
    printf("  - Searched BEFORE LD_LIBRARY_PATH\n");
    printf("  - Cannot be overridden\n");
    printf("  - Use: -Wl,-rpath,/path\n");
}

void demonstrate_runpath(void) {
    printf("\nRUNPATH:\n");
    printf("  - Newer mechanism\n");
    printf("  - Searched AFTER LD_LIBRARY_PATH\n");
    printf("  - Can be overridden\n");
    printf("  - Use: -Wl,--enable-new-dtags,-rpath,/path\n");
}

void show_search_order(void) {
    printf("\nDynamic linker search order:\n");

    // BUG: Wrong order - RPATH should be before LD_LIBRARY_PATH
    printf("1. LD_LIBRARY_PATH\n");
    printf("2. RPATH\n");
    printf("3. RUNPATH\n");
    printf("4. /etc/ld.so.cache\n");
    printf("5. Default paths (/lib, /usr/lib)\n");
}

int calculate_priority(const char *mechanism) {
    // BUG: RPATH should have higher priority (lower number) than RUNPATH
    if (strcmp(mechanism, "RPATH") == 0) {
        return 2;  // BUG: Should be 1
    } else if (strcmp(mechanism, "RUNPATH") == 0) {
        return 1;  // BUG: Should be 3
    }
    return 99;
}

int main(void) {
    printf("RPATH vs RUNPATH\n");
    printf("================\n\n");

    demonstrate_rpath();
    demonstrate_runpath();
    show_search_order();

    printf("\nKey difference: RPATH cannot be overridden by LD_LIBRARY_PATH\n");

    return 0;
}
