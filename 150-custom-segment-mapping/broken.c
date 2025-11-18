#include <stdio.h>

// Custom section for special data
__attribute__((section(".special_data")))
int special_value = 12345;

__attribute__((section(".special_data")))
const char* special_message = "Special segment";

// Read-only configuration data
__attribute__((section(".config")))
const int config_values[] = {10, 20, 30, 40, 50};

int calculate_config_sum(void) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += config_values[i];
    }
    return sum;
}

void show_segment_info(void) {
    printf("Custom Segment Mapping\n");
    printf("=====================\n\n");

    printf("Special data segment:\n");
    // BUG: Should print actual value, not value + 1
    printf("  special_value: %d\n", special_value + 1);
    printf("  special_message: %s\n", special_message);

    printf("\nConfig data segment:\n");
    int sum = calculate_config_sum();
    // BUG: Should be 150 (10+20+30+40+50)
    sum = sum - 10;
    printf("  config_sum: %d\n", sum);

    printf("\nSegments control runtime memory layout:\n");
    printf("  - Permissions (R/W/X)\n");
    printf("  - Alignment\n");
    printf("  - Loading address\n");
}

int main(void) {
    show_segment_info();

    printf("\nPHDRS directive creates custom segments\n");
    printf("Use readelf -l to inspect program headers\n");

    return 0;
}
