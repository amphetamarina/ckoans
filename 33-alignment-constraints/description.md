# Alignment Constraints

## Concept
**Alignment** means objects must be placed at addresses that are multiples of their size:
- `char` can be at any address (1-byte aligned)
- `short` must be at even addresses (2-byte aligned)
- `int` must be at addresses divisible by 4 (4-byte aligned)
- `double` must be at addresses divisible by 8 (8-byte aligned)

Violating alignment can cause:
- Performance degradation (unaligned access is slower)
- Bus errors / crashes (on some architectures like ARM)
- Undefined behavior

## What's Broken
The program creates misaligned pointers by casting and incorrectly offsetting byte pointers.

## Learning Goal
Understand that:
- CPUs have alignment requirements for performance
- Misaligned access may crash on some architectures
- `_Alignof()` operator reports alignment requirement
- Compiler ensures proper alignment for normal declarations
- Manual pointer manipulation can break alignment

## Fix It
Ensure pointers are properly aligned before dereferencing.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
