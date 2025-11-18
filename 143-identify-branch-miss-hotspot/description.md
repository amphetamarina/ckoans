# Identifying Branch-Miss Hotspots with perf

## Concept
Combine **perf record** with branch-miss sampling to find exactly which branches cause mispredictions.

**Workflow**:
1. `perf record -e branch-misses -g ./program` - sample on branch misses
2. `perf report` - see which functions/lines have most misses
3. `perf annotate` - show assembly with miss annotations

This pinpoints the exact branches causing performance problems, not just overall statistics.

**Interpreting results**:
- High miss samples on specific conditional → unpredictable data/logic
- Look for loops with complex conditions
- Consider branch-free alternatives (CMOV, lookup tables)

## What's Broken
The program has multiple functions with branches. One function has highly unpredictable branches causing most misses. Use `perf record -e branch-misses` to identify which function.

## Learning Goal
- Use `perf record -e branch-misses` to profile mispredictions
- Use `perf report` to identify hotspot functions
- Understand how to pinpoint problematic branches
- Learn to fix branch-heavy code

## Fix It
After identifying the hotspot with perf, eliminate or make predictable the problematic branch (e.g., by sorting data, using branchless code, or simplifying conditionals).

## Verify
```bash
gcc -O2 -g -o broken broken.c && ./broken
# Record branch misses:
perf record -e branch-misses -g ./broken
perf report --stdio | head -40
# After fixing, the hotspot should show fewer samples
diff <(./broken) expected.txt
```
