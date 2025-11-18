#include <stdio.h>
#include <stdint.h>

// Simulating different memory regions
// In embedded systems, these would be at specific hardware addresses

// Standard data section
int normal_data = 42;

// Custom memory region (e.g., fast SRAM)
__attribute__((section(".fastram")))
int fast_data = 100;

// Custom memory region (e.g., backup SRAM that survives resets)
__attribute__((section(".backup")))
int backup_data = 999;

void show_memory_regions(void) {
    printf("Custom Memory Region Demonstration\n");
    printf("==================================\n\n");

    printf("Memory layout:\n");
    printf("  normal_data (.data):   %d at %p\n", normal_data, (void*)&normal_data);
    printf("  fast_data (.fastram):  %d at %p\n", fast_data, (void*)&fast_data);
    printf("  backup_data (.backup): %d at %p\n", backup_data, (void*)&backup_data);
}

int verify_placement(void) {
    // Verify data is in correct regions
    // In real embedded code, we'd check against known memory ranges

    int errors = 0;

    // Normal data should be in standard RAM
    printf("\nVerifying section placement:\n");

    // Check fast_data value
    // BUG: Should check == 100, not == 101
    if (fast_data == 101) {
        printf("  [OK] fast_data in .fastram\n");
    } else {
        printf("  [FAIL] fast_data incorrect value\n");
        errors++;
    }

    // Check backup_data value
    if (backup_data == 999) {
        printf("  [OK] backup_data in .backup\n");
    } else {
        printf("  [FAIL] backup_data incorrect value\n");
        errors++;
    }

    // Check normal_data value
    if (normal_data == 42) {
        printf("  [OK] normal_data in .data\n");
    } else {
        printf("  [FAIL] normal_data incorrect value\n");
        errors++;
    }

    return errors;
}

int main(void) {
    show_memory_regions();

    int errors = verify_placement();

    if (errors == 0) {
        printf("\nAll sections placed correctly!\n");
    } else {
        printf("\nFound %d placement errors\n", errors);
    }

    printf("\nLinker scripts map sections to memory regions\n");
    printf("Use readelf -S to verify addresses\n");

    return errors;
}
