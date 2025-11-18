# Optimizer Assumptions

## Concept
The C compiler's optimizer makes assumptions based on the C standard:
1. **No aliasing** between different types (strict aliasing)
2. **No signed overflow** (signed overflow is UB)
3. **No null pointer dereference** (can eliminate null checks after dereference)
4. **No out-of-bounds access** (can hoist bounds checks)

These assumptions enable aggressive optimizations like:
- Reordering memory accesses
- Caching values in registers
- Eliminating redundant loads

Violating these assumptions leads to miscompilation.

## What's Broken
The program violates optimizer assumptions, causing different behavior at different optimization levels.

## Learning Goal
Understand that:
- Optimizer assumes you follow the rules
- `-O0` may work, `-O2` may break (due to optimizations)
- The optimizer doesn't add bugs - it exposes existing UB
- Common assumption: different types don't alias
- Understanding these assumptions is key to debugging optimization bugs

## Fix It
Write code that respects the optimizer's assumptions.

## Verify
```bash
gcc -O0 -o broken broken.c && ./broken
gcc -O2 -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
