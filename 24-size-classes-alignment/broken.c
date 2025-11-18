#include <stdio.h>
#include <stddef.h>

// Common size classes (in bytes)
size_t size_classes[] = {16, 32, 64, 128, 256, 512, 1024};
int num_classes = 7;

// Round up to next size class
size_t round_to_size_class(size_t requested) {
    for (int i = 0; i < num_classes; i++) {
        // BUG: Should check if requested <= size_classes[i]
        if (requested < size_classes[i]) {
            return size_classes[i];
        }
    }
    // For sizes larger than our classes, round up to alignment
    return (requested + 15) & ~15;  // Round to 16-byte alignment
}

void test_allocation(size_t requested) {
    size_t allocated = round_to_size_class(requested);
    size_t waste = allocated - requested;
    double waste_pct = (waste * 100.0) / allocated;

    printf("Request %4zu bytes → allocated %4zu bytes (waste: %3zu bytes, %.1f%%)\n",
           requested, allocated, waste, waste_pct);
}

int main(void) {
    printf("Size class allocation simulation:\n");
    printf("Size classes: ");
    for (int i = 0; i < num_classes; i++) {
        printf("%zu ", size_classes[i]);
    }
    printf("\n\n");

    test_allocation(1);
    test_allocation(16);
    test_allocation(17);
    test_allocation(31);
    test_allocation(32);
    test_allocation(33);
    test_allocation(100);
    test_allocation(256);
    test_allocation(500);

    return 0;
}
