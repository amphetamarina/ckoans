# Memcheck - Comprehensive Memory Error Detection

## Concept
**Valgrind Memcheck** is a memory error detector that finds:
- **Use of uninitialized memory**: Reading variables before writing to them
- **Invalid reads/writes**: Accessing memory out of bounds
- **Invalid frees**: Freeing memory incorrectly or twice
- **Memory leaks**: Allocated memory that's never freed
- **Mismatched allocation/deallocation**: Using `free()` on `new`, etc.

Run with: `valgrind --leak-check=full --track-origins=yes ./program`

Valgrind runs your program in a virtual CPU, tracking all memory operations.

## What's Broken
The program has multiple memory errors that Memcheck will detect.

## Learning Goal
- Understand Valgrind Memcheck's comprehensive error detection
- Read and interpret Memcheck error messages
- Distinguish between different types of memory errors
- Use `--track-origins=yes` to find uninitialized value sources

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run with Valgrind: `valgrind --leak-check=full --track-origins=yes ./broken`
3. Read the error reports and identify each issue
4. Fix all memory errors
5. Verify clean Valgrind output

## Verify
```bash
gcc -g broken.c -o broken
valgrind --leak-check=full --error-exitcode=1 ./broken 2>&1 | grep -E '(ERROR SUMMARY|definitely lost)'
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
