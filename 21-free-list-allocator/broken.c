#include <stdio.h>
#include <stdlib.h>

typedef struct FreeBlock {
    size_t size;
    struct FreeBlock *next;
} FreeBlock;

// Simulate free list (in real allocator, this would be in heap)
FreeBlock blocks[5] = {
    {32, &blocks[1]},
    {64, &blocks[2]},
    {128, &blocks[3]},
    {16, &blocks[4]},
    {256, NULL}
};

FreeBlock *free_list = &blocks[0];

// First-fit allocation simulation
FreeBlock* find_block(size_t size) {
    FreeBlock *current = free_list;

    while (current != NULL) {
        // BUG: Should check if current->size >= size (need at least 'size' bytes)
        if (current->size == size) {
            printf("Found exact block of size %zu\n", current->size);
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main(void) {
    printf("Free list state:\n");
    FreeBlock *b = free_list;
    while (b != NULL) {
        printf("  Block size: %zu\n", b->size);
        b = b->next;
    }

    printf("\nAllocating 50 bytes (first-fit):\n");
    FreeBlock *allocated = find_block(50);

    if (allocated) {
        printf("Success! Allocated block of size %zu\n", allocated->size);
    } else {
        printf("Allocation failed\n");
    }

    return 0;
}
