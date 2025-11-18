# Strict Aliasing Violations

## Concept
**Strict aliasing violations** occur when you access an object through a pointer of an incompatible type. Common violations:
- Accessing `int` through `float*`
- Type punning without proper techniques
- Reinterpreting data without unions or memcpy

The compiler assumes different pointer types don't alias, enabling optimizations. Violating this assumption causes undefined behavior.

## What's Broken
The program performs illegal type punning by casting between incompatible pointer types.

## Learning Goal
Understand that:
- Accessing an object through incompatible pointer is UB
- The optimizer assumes strict aliasing rules
- Common mistake: casting `int*` to `float*` for bit manipulation
- `-fstrict-aliasing` is enabled by default at `-O2` and higher
- `-Wstrict-aliasing` can warn about some violations
- Violations can cause silent miscompilation

## Fix It
Use unions, memcpy, or character arrays for safe type punning.

## Verify
```bash
gcc -O2 -Wstrict-aliasing -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
