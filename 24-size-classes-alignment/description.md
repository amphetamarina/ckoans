# Size Classes and Alignment

## Concept
Modern allocators use **size classes** (buckets) to reduce fragmentation and improve performance:

**Size classes**: Pre-defined allocation sizes (e.g., 16, 32, 64, 128, 256...)
- Request 20 bytes → get 32-byte block
- Reduces external fragmentation
- Enables fast lookup (no searching)
- Used by tcmalloc, jemalloc

**Alignment requirements**:
- Pointers must be aligned to natural boundaries (8 or 16 bytes on x86-64)
- `malloc` guarantees alignment for any type (typically 16 bytes)
- Misaligned access can cause crashes or performance penalties

## What's Broken
Code that rounds allocation sizes to size classes has incorrect rounding logic.

## Learning Goal
- Understand size class bucketing strategy
- See how alignment requirements affect allocation sizes
- Recognize trade-off between internal fragmentation and performance

## Fix It
Fix the size class selection to round up correctly.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
