# Free-List Allocator Model

## Concept
A **free-list allocator** manages heap memory by maintaining a linked list of free blocks. Common allocators (like `malloc`) use variations of this approach:

1. **Free blocks** contain metadata (size, next pointer)
2. On `malloc()`: Find suitable free block, split if needed, return pointer
3. On `free()`: Return block to free list, potentially coalesce with neighbors

Types of free-list strategies:
- **First-fit**: Use first block large enough
- **Best-fit**: Use smallest block that fits
- **Worst-fit**: Use largest available block

## What's Broken
A simplified free-list allocator simulation has incorrect logic in finding and removing free blocks.

## Learning Goal
- Understand free-list data structure
- See how allocators search for suitable blocks
- Recognize importance of block splitting and coalescing

## Fix It
Fix the free block search logic to correctly find and allocate blocks.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
