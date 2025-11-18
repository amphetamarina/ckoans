# Callgrind - Call Graph Profiler

## Concept
**Valgrind Callgrind** is a profiling tool that records:
- Function call counts
- Instruction counts per function
- Call graphs showing caller-callee relationships
- Cache simulation data

Run with: `valgrind --tool=callgrind ./program`

Analyze results with: `callgrind_annotate callgrind.out.<pid>`

Callgrind helps identify performance bottlenecks and hot paths.

## What's Broken
The program has inefficient algorithms. Use Callgrind to identify which functions consume the most time.

## Learning Goal
- Use Callgrind to profile programs
- Read callgrind_annotate output
- Identify hot functions (most executed)
- Optimize based on profiling data

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run with Callgrind: `valgrind --tool=callgrind ./broken`
3. Analyze results: `callgrind_annotate callgrind.out.*`
4. Identify the most expensive function
5. Optimize the algorithm

## Verify
```bash
gcc -g broken.c -o broken
valgrind --tool=callgrind ./broken
callgrind_annotate callgrind.out.* | head -30
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
