# Branch Misprediction with perf

## Concept
Modern CPUs use **branch prediction** to speculatively execute code before knowing the branch outcome. Mispredictions waste cycles and flush the pipeline.

**Branch prediction metrics**:
- `branches` - total branches executed
- `branch-misses` - incorrect predictions
- Miss rate = misses / branches (aim for <5%)

**Patterns that cause misses**:
- Random/unpredictable data
- Complex conditional logic
- Irregular access patterns

**Usage**: `perf stat -e branches,branch-misses ./program`

## What's Broken
The program processes unsorted data with unpredictable branches. Sorting the data first makes branches more predictable, reducing misses dramatically.

## Learning Goal
- Use perf to measure branch mispredictions
- Understand how data patterns affect branch prediction
- See the performance impact of branch misses
- Learn that sorting can improve branch prediction

## Fix It
Sort the data array before processing to make the branch pattern predictable.

## Verify
```bash
gcc -O2 -o broken broken.c && ./broken
# Measure branch misses:
perf stat -e branches,branch-misses ./broken
# After sorting, branch-miss rate should drop significantly
diff <(./broken) expected.txt
```
