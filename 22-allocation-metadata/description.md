# Allocation Metadata

## Concept
Heap allocators store **metadata** before/after each allocated block:

```
[metadata header][user data...][optional footer]
```

Typical metadata includes:
- **Size** of the allocation (for freeing)
- **Status flags** (allocated/free, previous block free, etc.)
- **Boundary tags** for coalescing adjacent free blocks
- **Magic numbers** for corruption detection

The pointer returned by `malloc()` points to the **user data**, not the metadata. `free()` must calculate the metadata location by subtracting the header size.

## What's Broken
Code that simulates extracting allocation metadata has incorrect pointer arithmetic.

## Learning Goal
- Understand malloc returns pointer to data, not block start
- See metadata lives before the returned pointer
- Recognize size calculations must account for metadata overhead

## Fix It
Fix the pointer arithmetic to correctly access the metadata header.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
