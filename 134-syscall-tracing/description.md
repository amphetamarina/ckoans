# Syscall Tracing with strace

## Concept
**strace** traces system calls made by a program. Every interaction with the kernel (file I/O, memory allocation, process creation) goes through syscalls.

**Key syscalls**:
- `open()`/`openat()` - open files
- `read()`/`write()` - I/O operations
- `brk()`/`mmap()` - memory allocation
- `execve()` - execute programs
- `exit_group()` - terminate process

strace shows syscall arguments, return values, and errors. Use `strace -e trace=<category>` to filter (e.g., `-e trace=file` for file operations).

## What's Broken
The program attempts to read from a file but uses the wrong syscall sequence, causing it to fail silently.

## Learning Goal
- Use strace to observe syscall sequences
- Understand the open → read → close pattern
- See how syscalls fail (return -1, set errno)
- Trace specific syscall categories

## Fix It
Correct the file descriptor usage to match the proper syscall sequence.

## Verify
```bash
gcc -o broken broken.c && ./broken
# Use strace to debug:
strace -e trace=file,read ./broken
diff <(./broken) expected.txt
```
