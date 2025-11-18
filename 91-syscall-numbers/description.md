# Syscall Numbers

## Concept
Each system call is identified by a unique **syscall number**. When making a syscall:
- The syscall number goes in a specific register (RAX on x86-64)
- Arguments go in other registers (RDI, RSI, RDX, R10, R8, R9)
- The kernel uses the number to dispatch to the correct handler

**System call table** (`/usr/include/asm/unistd_64.h` on x86-64):
```c
#define __NR_read    0
#define __NR_write   1
#define __NR_open    2
#define __NR_close   3
#define __NR_getpid  39
#define __NR_fork    57
#define __NR_execve  59
```

**Why numbers**:
- Fast: Direct array indexing into syscall table
- Stable ABI: Numbers don't change for backward compatibility
- Architecture-specific: Different architectures have different numbers
- Versioning: Old syscalls deprecated, new ones added

**Using `syscall()` wrapper**:
```c
#include <sys/syscall.h>
#include <unistd.h>

long result = syscall(SYS_getpid);  // SYS_getpid is a macro for __NR_getpid
```

**Finding syscall numbers**:
- Header: `/usr/include/asm/unistd_64.h` (or `unistd_32.h`)
- Reference: `man 2 syscalls`
- Runtime: `ausyscall --dump` (if auditd installed)
- strace: Shows both names and numbers

## What's Broken
The program uses incorrect syscall numbers for the operations it wants to perform.

## Learning Goal
Understand that:
- System calls are identified by numbers, not names
- Numbers are architecture-specific
- Must use correct number for intended operation
- `syscall()` provides direct access with numbers

## Fix It
Correct the syscall numbers to match the intended operations.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
