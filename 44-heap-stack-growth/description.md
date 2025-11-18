# Heap and Stack Growth

## Concept
The **heap** and **stack** grow in opposite directions in memory:

**Stack**:
- Grows downward (high addresses → low addresses)
- Automatic allocation (function calls, local variables)
- Limited size (typically 8 MB on Linux)
- Fast allocation (just move stack pointer)
- Stack overflow when limit exceeded

**Heap**:
- Grows upward (low addresses → high addresses)
- Manual allocation (malloc/free)
- Can grow to available RAM
- Slower allocation (needs memory manager)
- Fragmentation possible

They grow toward each other, separated by a large gap.

## What's Broken
The program doesn't account for stack growth direction or limited stack size.

## Learning Goal
Understand that:
- Stack grows down, heap grows up
- Stack has hard size limit (ulimit -s shows it)
- Recursive functions can overflow stack
- Large arrays on stack can overflow stack
- Heap is more flexible but requires manual management
- Stack pointer decreases on function call, increases on return

## Fix It
Move large allocations from stack to heap to avoid overflow.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
