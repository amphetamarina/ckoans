# Error Path Analysis with strace

## Concept
**strace** shows syscall return values and errors, making it invaluable for debugging failures. When a syscall fails, strace displays:
- Return value (typically -1)
- errno symbolic name (e.g., ENOENT, EACCES)
- Error description

**Common error patterns**:
- `ENOENT` - No such file or directory
- `EACCES` - Permission denied
- `EINVAL` - Invalid argument
- `EBADF` - Bad file descriptor

Use `strace -e trace=<syscalls>` to focus on specific calls. The `-o` flag writes output to a file for analysis.

## What's Broken
The program fails to create a directory but doesn't properly check or handle the error, leading to cascading failures.

## Learning Goal
- Use strace to identify which syscall fails first
- Understand error propagation through syscall sequences
- See how errno is set by failed syscalls
- Debug silent failures with strace

## Fix It
Add proper error checking to detect the first failure point, or fix the syscall arguments to avoid the error.

## Verify
```bash
gcc -o broken broken.c && ./broken
# Trace to see the error:
strace -e trace=mkdir,open ./broken 2>&1 | grep -E "(mkdir|open|EEXIST)"
diff <(./broken) expected.txt
```
