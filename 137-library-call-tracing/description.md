# Library Call Tracing with ltrace

## Concept
**ltrace** traces library function calls (libc, libm, etc.), while strace traces syscalls. Many C functions are library wrappers around syscalls.

**Key differences**:
- `ltrace` - shows calls like `strlen()`, `malloc()`, `printf()`
- `strace` - shows calls like `write()`, `brk()`, `mmap()`

Some library functions don't make syscalls (e.g., `strlen()` is pure computation). Others make many syscalls (e.g., `printf()` may call `write()` multiple times).

**Usage**: `ltrace -e <func>` to filter specific functions.

## What's Broken
The program uses `strcat()` but with a destination buffer that's too small, causing undefined behavior. ltrace will show the string operations.

## Learning Goal
- Use ltrace to trace library function calls
- See the difference between library calls and syscalls
- Understand buffer overflow at the library level
- Debug string manipulation bugs

## Fix It
Allocate a properly sized buffer for the concatenated string, or use safer alternatives like `snprintf()`.

## Verify
```bash
gcc -o broken broken.c && ./broken
# Use ltrace to see string operations:
ltrace -e 'str*' ./broken
diff <(./broken) expected.txt
```
