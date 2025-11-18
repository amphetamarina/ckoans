# Returning Pointer to Dead Stack (Undefined Behavior)

## Concept
Returning a pointer to a local (automatic) variable is **undefined behavior** because:
- Local variables are destroyed when function returns
- The pointer becomes a **dangling pointer** to invalid memory
- That stack memory may be reused by subsequent function calls
- Dereferencing it can crash, return garbage, or appear to work

This is one of the most common and dangerous bugs in C.

## What's Broken
Functions return pointers to local variables, creating dangling pointers.

## Learning Goal
Understand that:
- Stack memory is reclaimed when function returns
- Pointers to local variables become invalid after function exit
- This is undefined behavior (UB) - anything can happen
- Solution: use `static`, heap allocation, or caller-provided buffer
- Compiler warnings (`-Wreturn-local-addr`) can catch this

## Fix It
Use either:
1. `static` storage (if single-threaded and read-only is OK)
2. Heap allocation with `malloc()` (caller must free)
3. Caller-provided buffer (pass pointer as parameter)

## Verify
```bash
gcc -Wall -Wextra -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
