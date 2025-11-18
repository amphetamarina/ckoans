#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Simulated allocation metadata header
typedef struct {
    size_t size;
    uint32_t magic;  // For corruption detection
    int is_allocated;
} BlockHeader;

#define MAGIC 0xDEADBEEF

// Simulate what malloc does internally
void* my_malloc(size_t size) {
    // Allocate space for header + requested size
    size_t total = sizeof(BlockHeader) + size;
    void *block = malloc(total);

    if (block) {
        BlockHeader *header = (BlockHeader*)block;
        header->size = size;
        header->magic = MAGIC;
        header->is_allocated = 1;

        // Return pointer after header (user data area)
        return (char*)block + sizeof(BlockHeader);
    }
    return NULL;
}

// Simulate what free does - must find header from user pointer
void my_free(void *ptr) {
    if (!ptr) return;

    // BUG: Wrong calculation - should subtract sizeof(BlockHeader)
    BlockHeader *header = (BlockHeader*)((char*)ptr + sizeof(BlockHeader));

    printf("Freeing block: size=%zu, magic=0x%X, allocated=%d\n",
           header->size, header->magic, header->is_allocated);

    // In real implementation, would mark as free and return to free list
    // For this simulation, just free the original block
    free(header);
}

int main(void) {
    printf("Allocating 64 bytes...\n");
    void *ptr = my_malloc(64);

    printf("User pointer: %p\n", ptr);
    printf("Header should be %zu bytes before\n", sizeof(BlockHeader));

    printf("\nFreeing...\n");
    my_free(ptr);

    return 0;
}
