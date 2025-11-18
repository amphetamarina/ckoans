# Flamegraphs with perf

## Concept
**Flamegraphs** visualize where CPU time is spent by showing call stack samples. Width represents time spent; colors are arbitrary.

**perf record workflow**:
1. `perf record -F 99 -g ./program` - sample at 99Hz with call graphs
2. `perf script` - dump stack traces
3. `stackcollapse-perf.pl` - collapse stacks
4. `flamegraph.pl` - generate SVG

**Reading flamegraphs**:
- X-axis: alphabetically sorted functions (NOT time)
- Y-axis: stack depth (caller → callee from bottom to top)
- Width: percentage of total time

Wide bars = hotspots consuming significant CPU time.

## What's Broken
The program has a deeply nested call chain with an inefficient function that dominates CPU time. Using perf record and examining the output reveals the hotspot.

## Learning Goal
- Use `perf record` to capture call stacks
- Use `perf report` to examine profiling data
- Understand how to identify CPU hotspots
- See how function call overhead appears in profiles

## Fix It
Optimize or eliminate the inefficient function shown in the perf report.

## Verify
```bash
gcc -O0 -g -o broken broken.c && ./broken
# Profile the program:
perf record -g ./broken
perf report --stdio | head -30
# After fixing, hotspot should move or total time should decrease
diff <(./broken) expected.txt
```
