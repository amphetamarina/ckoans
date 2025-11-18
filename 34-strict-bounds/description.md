# Strict Bounds Rules

## Concept
C has strict rules about pointer arithmetic bounds:
- You can form a pointer to one element **past the end** of an array
- You **cannot dereference** that one-past-the-end pointer
- Going further than one-past-the-end is **undefined behavior**
- Pointer arithmetic outside allocated object bounds is UB

Valid: `arr + n` where `0 <= n <= size`
Invalid: `arr + n` where `n > size`
Never dereference: `*(arr + size)`

## What's Broken
The program performs out-of-bounds pointer arithmetic and dereferencing.

## Learning Goal
Understand that:
- One-past-the-end pointer is valid for comparison
- It exists to support loop idioms: `for (p = arr; p != arr + size; p++)`
- Dereferencing out-of-bounds pointer is undefined behavior
- AddressSanitizer (ASan) can detect some bounds violations
- Bounds checking is NOT automatic in C

## Fix It
Correct the loop bounds to avoid out-of-bounds access.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
gcc -fsanitize=address -g -o broken broken.c && ./broken
```
