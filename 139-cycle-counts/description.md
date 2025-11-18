# CPU Cycle Counts with perf

## Concept
**perf** uses hardware performance counters to measure program execution. CPU cycles are the fundamental unit of execution time.

**Key metrics**:
- `cycles` - total CPU cycles consumed
- `instructions` - total instructions executed
- `IPC` (Instructions Per Cycle) - efficiency metric
- Higher IPC = better CPU utilization

**Usage**: `perf stat ./program` shows basic counters.

Poor IPC (<1.0) indicates:
- Cache misses
- Branch mispredictions
- Memory stalls
- Inefficient algorithms

## What's Broken
The program has an inefficient loop that performs redundant calculations, wasting CPU cycles. The algorithm could be optimized to reduce cycle count.

## Learning Goal
- Use `perf stat` to measure CPU cycles
- Understand Instructions Per Cycle (IPC)
- See how algorithmic inefficiency shows up in cycle counts
- Compare cycle counts before/after optimization

## Fix It
Eliminate redundant calculations by hoisting invariant computations out of the inner loop.

## Verify
```bash
gcc -O0 -o broken broken.c && ./broken
# Measure cycles:
perf stat -e cycles,instructions ./broken
# After fixing, cycles should decrease significantly
diff <(./broken) expected.txt
```
