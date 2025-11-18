# Dynamic (Heap) Storage Duration

## Concept
Objects with **dynamic storage duration** are:
- Allocated explicitly with `malloc()`, `calloc()`, or `realloc()`
- Freed explicitly with `free()`
- Persist until explicitly freed (not tied to scope)
- Allocated on the heap, not the stack
- Must be manually managed (no automatic cleanup)

## What's Broken
The program has a memory leak - allocated memory is never freed.

## Learning Goal
Understand that:
- Dynamic memory persists beyond function scope
- Every `malloc()` must have a corresponding `free()`
- Memory leaks occur when allocated memory is not freed
- Dynamic storage gives you control but requires responsibility
- Use tools like `valgrind` to detect leaks

## Fix It
Add the missing `free()` call to release the allocated memory.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
valgrind --leak-check=full ./broken 2>&1 | grep "no leaks are possible"
```
