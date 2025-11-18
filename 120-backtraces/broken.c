#include <stdio.h>
#include <string.h>

int string_length(const char *str) {
    // BUG: Missing null check
    return strlen(str);
}

int process_string(const char *str) {
    int len = string_length(str);
    return len * 2;
}

int calculate_total(const char *str1, const char *str2) {
    int len1 = process_string(str1);
    int len2 = process_string(str2);
    return len1 + len2;
}

void print_array(int *arr, int size) {
    // BUG: Missing null check
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void process_array(int *arr, int size) {
    if (size > 0) {
        print_array(arr, size);
    }
}

int main(void) {
    printf("Backtrace debugging:\n\n");

    // This will work
    int total1 = calculate_total("hello", "world");
    printf("Total length: %d\n", total1);

    // BUG: This will crash - passing NULL
    int total2 = calculate_total("test", NULL);
    printf("Total length: %d\n", total2);

    // This will also crash
    int *arr = NULL;
    process_array(arr, 5);

    return 0;
}
