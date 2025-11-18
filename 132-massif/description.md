# Massif - Heap Profiler

## Concept
**Valgrind Massif** is a heap profiler that tracks:
- **Heap memory usage over time**: Shows memory growth patterns
- **Allocation sites**: Where memory is allocated
- **Peak memory usage**: Maximum heap consumption
- **Stack traces**: Shows call chains for allocations

Run with: `valgrind --tool=massif ./program`

Visualize with: `ms_print massif.out.<pid>`

Massif helps identify memory bloat and optimize heap usage.

## What's Broken
The program has excessive heap allocations and memory growth. Use Massif to find where memory is being consumed.

## Learning Goal
- Use Massif to profile heap memory usage
- Read ms_print output and graphs
- Identify memory-hungry allocations
- Optimize memory usage patterns

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run with Massif: `valgrind --tool=massif ./broken`
3. Analyze results: `ms_print massif.out.*`
4. Identify peak memory usage and allocation sites
5. Optimize to reduce memory footprint

## Verify
```bash
gcc -g broken.c -o broken
valgrind --tool=massif ./broken
ms_print massif.out.* | grep -A 5 "peak"
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
