#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulate file list from filesystem
const char* files_unsorted[] = {
    "zebra.c",
    "apple.c",
    "mango.c",
    "banana.c",
    NULL
};

// Comparator for qsort
int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void show_unstable_sources(void) {
    printf("Stable Ordering for Reproducible Builds\n");
    printf("========================================\n\n");

    printf("Sources of unstable ordering:\n");
    printf("  1. Filesystem readdir() order\n");
    printf("  2. Hash table iteration\n");
    // BUG: Missing "3. Parallel builds"
    printf("  3. Wildcard expansion\n");
    printf("  4. ASLR (address space layout)\n");
}

void demonstrate_unstable_order(void) {
    printf("\nUnstable file processing:\n");

    // BUG: Processing in unsorted order
    printf("  Files in filesystem order:\n");
    for (int i = 0; files_unsorted[i] != NULL; i++) {
        printf("    - %s\n", files_unsorted[i]);
    }
}

void demonstrate_stable_order(void) {
    printf("\nStable file processing:\n");

    // Count files
    int count = 0;
    while (files_unsorted[count] != NULL) {
        count++;
    }

    // Copy and sort
    const char** files_sorted = malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++) {
        files_sorted[i] = files_unsorted[i];
    }

    qsort(files_sorted, count, sizeof(char*), compare_strings);

    printf("  Files in sorted order:\n");
    for (int i = 0; i < count; i++) {
        printf("    - %s\n", files_sorted[i]);
    }

    free(files_sorted);
}

void show_build_system_examples(void) {
    printf("\nBuild system solutions:\n");

    printf("  Makefile:\n");
    printf("    SRCS := $(sort $(wildcard *.c))\n");

    printf("\n  CMake:\n");
    printf("    file(GLOB SRCS \"*.c\")\n");
    printf("    list(SORT SRCS)\n");

    printf("\n  Shell:\n");
    // BUG: Should be "$(ls *.c | sort)"
    printf("    gcc $(ls *.c) -o program\n");
}

int main(void) {
    show_unstable_sources();
    demonstrate_unstable_order();
    demonstrate_stable_order();
    show_build_system_examples();

    printf("\nAlways sort inputs for reproducible builds!\n");

    return 0;
}
