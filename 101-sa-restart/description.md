# SA_RESTART Flag

## Concept
When a signal interrupts a blocking system call (like read, write, or sleep), the call can either:

1. **Return EINTR** - Caller must check errno and retry manually
2. **Automatically restart** - Syscall resumes after the handler returns

The **SA_RESTART** flag in sigaction controls this behavior:
- **Without SA_RESTART**: Interrupted syscalls return -1 with errno = EINTR
- **With SA_RESTART**: Most syscalls automatically restart after signal handling

This simplifies code by eliminating the need to manually check for and handle EINTR.

## What's Broken
The program's signal handler doesn't use SA_RESTART, causing read() to fail with EINTR when interrupted by signals.

## Learning Goal
- Understand how signals interrupt blocking syscalls
- Learn when syscalls return EINTR
- Use SA_RESTART to automatically restart interrupted syscalls

## Fix It
Add the SA_RESTART flag to the sigaction structure.

## Verify
```bash
gcc -o broken broken.c && timeout 3 ./broken
diff <(timeout 3 ./broken) expected.txt
```
