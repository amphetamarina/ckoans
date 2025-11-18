#include <stdio.h>

// Place variables in custom sections
__attribute__((section(".mydata")))
int custom_data = 100;

__attribute__((section(".mydata")))
int custom_array[4] = {1, 2, 3, 4};

__attribute__((section(".myrodata")))
const char* custom_string = "Custom section data";

// Place function in custom section
__attribute__((section(".myfuncs")))
int custom_function(int x) {
    return x * 2;
}

void show_section_info(void) {
    printf("Section Assignment Demonstration\n");
    printf("================================\n\n");

    printf("Variables in custom sections:\n");
    printf("  custom_data (.mydata): %d\n", custom_data);
    printf("  custom_string (.myrodata): %s\n", custom_string);

    // BUG: Should sum all elements (1+2+3+4 = 10), not just first
    int sum = custom_array[0];
    printf("  custom_array sum (.mydata): %d\n", sum);
}

int main(void) {
    show_section_info();

    printf("\nFunction in custom section:\n");
    int result = custom_function(21);
    // BUG: Should be 42, not 41
    result = result - 1;
    printf("  custom_function result: %d\n", result);

    printf("\nLinker scripts control section placement\n");

    return 0;
}
