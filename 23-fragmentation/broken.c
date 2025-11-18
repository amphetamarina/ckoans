#include <stdio.h>
#include <stdlib.h>

typedef struct FreeBlock {
    size_t size;
    struct FreeBlock *next;
} FreeBlock;

// Simulated fragmented heap: total 200 bytes free, but in small chunks
FreeBlock blocks[5] = {
    {32, &blocks[1]},
    {48, &blocks[2]},
    {40, &blocks[3]},
    {36, &blocks[4]},
    {44, NULL}
};

FreeBlock *free_list = &blocks[0];

void print_free_list(void) {
    size_t total_free = 0;
    int num_blocks = 0;

    FreeBlock *b = free_list;
    while (b != NULL) {
        printf("  Free block: %zu bytes\n", b->size);
        total_free += b->size;
        num_blocks++;
        b = b->next;
    }

    printf("Total free: %zu bytes in %d blocks\n", total_free, num_blocks);
}

int can_allocate(size_t size) {
    FreeBlock *b = free_list;
    while (b != NULL) {
        if (b->size >= size) {
            return 1;
        }
        b = b->next;
    }
    return 0;
}

int main(void) {
    printf("Fragmented heap state:\n");
    print_free_list();

    size_t request = 100;
    printf("\nTrying to allocate %zu bytes...\n", request);

    if (can_allocate(request)) {
        printf("Success: Found contiguous block\n");
    } else {
        printf("Failed: External fragmentation detected\n");

        // Calculate total free to show we have enough total space
        size_t total = 0;
        FreeBlock *b = free_list;
        while (b != NULL) {
            total += b->size;
            b = b->next;
        }

        // BUG: Should check if total >= request to prove fragmentation
        if (total == request) {
            printf("Total free (%zu) >= request (%zu), but fragmented!\n", total, request);
        }
    }

    return 0;
}
