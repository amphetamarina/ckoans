# Cache Miss Patterns with perf

## Concept
**CPU caches** store recently accessed memory. Cache misses force expensive main memory access (100x+ slower than L1 cache).

**Cache hierarchy**:
- L1: ~4 cycles, ~32KB per core
- L2: ~12 cycles, ~256KB per core
- L3: ~40 cycles, shared, several MB
- RAM: ~200 cycles

**perf cache events**:
- `cache-references` - total cache accesses
- `cache-misses` - data not in cache
- `LLC-loads` / `LLC-load-misses` - Last Level Cache

**Usage**: `perf stat -e cache-references,cache-misses ./program`

## What's Broken
The program accesses a 2D array in column-major order (wrong for C's row-major layout), causing cache line misses. Switching to row-major order dramatically improves cache utilization.

## Learning Goal
- Use perf to measure cache misses
- Understand spatial locality and cache lines
- See how access patterns affect cache performance
- Learn the importance of row-major vs column-major access

## Fix It
Change the loop order to access the array in row-major order (outer loop on rows, inner loop on columns).

## Verify
```bash
gcc -O2 -o broken broken.c && ./broken
# Measure cache misses:
perf stat -e cache-references,cache-misses ./broken
# After fixing, cache misses should drop significantly
diff <(./broken) expected.txt
```
