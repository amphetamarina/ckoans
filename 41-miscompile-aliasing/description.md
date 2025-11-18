# Miscompile from Invalid Aliasing at -O2

## Concept
Strict aliasing violations can cause **silent miscompilation** at optimization levels `-O2` and above:
- Code may work correctly at `-O0` (no optimizations)
- Same code fails at `-O2` (with optimizations)
- The optimizer assumes strict aliasing and reorders/caches accordingly
- Result: wrong values, missed updates, or logic errors

This is one of the most insidious bugs in C programming.

## What's Broken
The program has a strict aliasing violation that causes miscompilation at `-O2`.

## Learning Goal
Understand that:
- `-O0` and `-O2` can produce different results for UB code
- The optimizer doesn't "break" code - it exposes existing bugs
- Strict aliasing violations manifest as optimization bugs
- Always test with optimizations enabled
- Use `-fno-strict-aliasing` as a temporary workaround (not a fix!)
- Proper fix: use unions, memcpy, or avoid type punning

## Task
1. Compile with `-O0`: `gcc -O0 -o broken broken.c && ./broken`
2. Compile with `-O2`: `gcc -O2 -o broken broken.c && ./broken`
3. Compare the outputs (should differ due to UB)
4. Fix the aliasing violation
5. Verify both optimization levels produce correct output

## Verify
```bash
gcc -O2 -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
