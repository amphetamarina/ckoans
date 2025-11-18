# Debugging Hangs with strace: Wrong File Descriptor

## Concept
Programs that hang are often blocked on I/O. **strace** shows exactly which syscall is blocking and on which file descriptor.

**strace flags for debugging hangs**:
- `strace -T` - show time spent in each syscall
- `strace -tt` - absolute timestamps with microseconds
- `strace -e trace=read,write,poll` - focus on I/O syscalls

File descriptors:
- 0 = stdin, 1 = stdout, 2 = stderr
- Other fds from `open()`, `pipe()`, `socket()`

Using the wrong fd causes blocking on unexpected sources (e.g., reading from stdin instead of a file).

## What's Broken
The program tries to read from a file but accidentally reads from stdin (fd 0), causing it to hang waiting for user input.

## Learning Goal
- Use strace to identify which fd is being read
- Understand the standard file descriptors (0, 1, 2)
- See how wrong fd usage causes hangs
- Debug blocking I/O with strace

## Fix It
Use the correct file descriptor returned by `open()` instead of accidentally using stdin.

## Verify
```bash
gcc -o broken broken.c
# This will hang waiting for stdin - use Ctrl+C:
# echo "" | timeout 2 strace -e trace=read ./broken 2>&1 | grep "read("
# After fixing:
./broken
diff <(./broken) expected.txt
```
