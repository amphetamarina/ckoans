# Stack Pointer vs Frame Pointer

## Concept
Two critical pointers manage the stack:
- **Stack Pointer (SP/RSP)**: Points to top of stack, changes with push/pop
- **Frame Pointer (BP/RBP)**: Points to current frame base, stable reference for locals

## What's Broken
Code with stack manipulation that needs fixing.

## Learning Goal
- Understand SP vs BP roles
- See how function calls adjust these pointers
- Understand frame-based local variable access

## Task
Fix the variable access pattern.

## Verify
```bash
gcc -fno-omit-frame-pointer -O0 -S broken.c -o broken.s
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
