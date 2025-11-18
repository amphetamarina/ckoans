# Fragmentation

## Concept
**Heap fragmentation** occurs when free memory is divided into small, non-contiguous blocks:

**External fragmentation**: Total free space is sufficient, but no single contiguous block is large enough
- Example: 100 bytes free in 10-byte chunks, can't allocate 50 bytes

**Internal fragmentation**: Allocated block is larger than requested
- Example: Request 33 bytes, get 64-byte block (31 bytes wasted)

Mitigation strategies:
- **Coalescing**: Merge adjacent free blocks
- **Compaction**: Move allocations to consolidate free space
- **Size classes**: Reduce internal fragmentation with size buckets

## What's Broken
Code that simulates fragmentation detection has incorrect logic for identifying when allocation fails due to fragmentation.

## Learning Goal
- Understand external vs internal fragmentation
- See how allocation patterns cause fragmentation
- Recognize importance of coalescing free blocks

## Fix It
Fix the fragmentation detection logic.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
