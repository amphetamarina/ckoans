# Cachegrind - Cache and Branch Prediction Profiler

## Concept
**Valgrind Cachegrind** simulates CPU caches and measures:
- **L1/L2/LL cache misses**: Data and instruction cache misses
- **Branch mispredictions**: Conditional branches taken/not-taken
- **Memory access patterns**: Identifies cache-unfriendly code

Run with: `valgrind --tool=cachegrind ./program`

Analyze results with: `cg_annotate cachegrind.out.<pid>`

Cachegrind helps optimize memory access patterns for better cache utilization.

## What's Broken
The program has poor cache locality. Use Cachegrind to identify cache-unfriendly access patterns.

## Learning Goal
- Use Cachegrind to analyze cache behavior
- Understand cache misses and their impact
- Identify row-major vs column-major access issues
- Optimize memory access patterns for better cache locality

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run with Cachegrind: `valgrind --tool=cachegrind ./broken`
3. Analyze results: `cg_annotate cachegrind.out.*`
4. Identify functions with high cache miss rates
5. Fix memory access patterns

## Verify
```bash
gcc -g broken.c -o broken
valgrind --tool=cachegrind ./broken 2>&1 | grep -E '(D1|LL) '
cg_annotate cachegrind.out.* | head -40
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
