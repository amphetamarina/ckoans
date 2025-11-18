# Blocking Detection with strace

## Concept
**Blocking syscalls** suspend execution until a condition is met. strace with timestamps (`-T` or `-r`) reveals where your program spends time waiting.

**Common blocking syscalls**:
- `read()` - waits for data
- `write()` - waits for buffer space
- `select()`/`poll()`/`epoll_wait()` - I/O multiplexing
- `nanosleep()` - explicit sleep
- `wait()`/`waitpid()` - wait for child process

Use `strace -T` to show time spent in each syscall. Use `strace -r` for relative timestamps between calls.

## What's Broken
The program appears to hang because it's blocked waiting on a pipe that will never have data. The issue is reading from the wrong end of a pipe.

## Learning Goal
- Use strace -T to identify blocking syscalls
- Understand pipe semantics (read end vs write end)
- See how programs hang on blocking I/O
- Debug deadlocks with strace

## Fix It
Correct the pipe usage to read from the proper file descriptor after writing data to it.

## Verify
```bash
gcc -o broken broken.c
# This will hang - use Ctrl+C to stop:
# timeout 2 strace -T ./broken 2>&1 | grep read
# After fixing:
./broken
diff <(./broken) expected.txt
```
