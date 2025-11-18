# Interpret Callgrind Diff - Compare Performance Changes

## Concept
**Callgrind diff** compares two profiling runs to measure performance changes:
- Shows instruction count differences per function
- Identifies performance improvements or regressions
- Validates that optimizations actually improved performance

Compare runs with: `cg_diff callgrind.out.before callgrind.out.after`

This is essential for:
- Verifying optimizations worked
- Detecting performance regressions
- A/B testing different implementations

## What's Broken
The program has two implementations: one slow, one fast. Use Callgrind to measure the difference.

## Learning Goal
- Profile code before and after optimization
- Use cg_diff to compare two runs
- Interpret positive/negative instruction count changes
- Verify that optimizations achieved the expected speedup

## Task
1. Compile with SLOW defined: `gcc -g -DSLOW broken.c -o broken_slow`
2. Profile slow version: `valgrind --tool=callgrind --callgrind-out-file=callgrind.out.slow ./broken_slow`
3. Compile with FAST defined: `gcc -g -DFAST broken.c -o broken_fast`
4. Profile fast version: `valgrind --tool=callgrind --callgrind-out-file=callgrind.out.fast ./broken_fast`
5. Compare: `cg_diff callgrind.out.slow callgrind.out.fast`
6. Fix the program to always use the fast version

## Verify
```bash
# Profile both versions
gcc -g -DSLOW broken.c -o broken_slow
gcc -g -DFAST broken.c -o broken_fast
valgrind --tool=callgrind --callgrind-out-file=cg.slow ./broken_slow 2>&1 > /dev/null
valgrind --tool=callgrind --callgrind-out-file=cg.fast ./broken_fast 2>&1 > /dev/null
cg_diff cg.slow cg.fast | head -20

# After fixing, should use fast version
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
