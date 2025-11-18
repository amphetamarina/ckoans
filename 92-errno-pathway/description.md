# Errno Pathway

## Concept
**`errno`** is the mechanism for reporting errors from system calls and library functions.

**How it works**:
1. **System call fails** in kernel
2. **Kernel returns** -1 (or sometimes -errno)
3. **C library wrapper** detects error return
4. **Wrapper sets errno** to the error code (positive value)
5. **Wrapper returns** -1 to caller
6. **User code checks** return value and errno

**Key points**:
- `errno` is a thread-local variable (actually a macro)
- Only valid immediately after a failed call
- **Must check return value first** - errno may contain stale values
- Not automatically cleared on success
- Error codes defined in `<errno.h>` (ENOENT, EACCES, etc.)

**Using errno**:
```c
#include <errno.h>
#include <string.h>

if (some_syscall() == -1) {
    printf("Error: %s\n", strerror(errno));  // Human-readable
    // Or use perror():
    perror("some_syscall");
}
```

**Common errors**:
- `ENOENT` (2) - No such file or directory
- `EACCES` (13) - Permission denied
- `EINVAL` (22) - Invalid argument
- `ENOMEM` (12) - Out of memory

**Thread safety**:
- In modern glibc, `errno` expands to `(*__errno_location())`
- Each thread has its own errno location
- Thread-safe by design

## What's Broken
The program incorrectly checks errno or fails to check return values before examining errno.

## Learning Goal
Understand that:
- errno is only meaningful after a function returns an error
- Must check return value first
- errno provides detailed error information
- Use `strerror()` or `perror()` for readable messages

## Fix It
Add proper error checking and errno handling.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
