# Memory Leak - Detect with Valgrind

## Concept
A **memory leak** occurs when allocated memory is not freed before all references to it are lost. Valgrind's **Memcheck** tool detects:

- **Definitely lost**: No pointers to the block exist
- **Indirectly lost**: Block is reachable only through leaked blocks
- **Possibly lost**: Interior pointers exist but not to block start
- **Still reachable**: Pointers exist at exit (not necessarily a bug)

Valgrind tracks all allocations and reports leaks at program exit.

## What's Broken
The program has memory leaks that Valgrind will detect. Fix them.

## Learning Goal
- Understand how memory leaks occur
- Use Valgrind to detect and locate leaks
- See leak categories (definitely lost, still reachable, etc.)

## Task
1. Run with Valgrind: `valgrind --leak-check=full ./broken`
2. Identify the leaked allocations
3. Add appropriate `free()` calls
4. Verify no leaks remain

## Verify
```bash
gcc -g -o broken broken.c
valgrind --leak-check=full --error-exitcode=1 ./broken 2>&1 | grep -E '(definitely lost|ERROR SUMMARY)'
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
