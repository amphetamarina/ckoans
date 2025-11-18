# Blocking vs Non-blocking I/O

## Concept
By default, file descriptors are **blocking**:
- **read()** blocks until data is available
- **write()** blocks until buffer space is available

With the **O_NONBLOCK** flag, operations become non-blocking:
- **read()** returns immediately with EAGAIN/EWOULDBLOCK if no data is ready
- **write()** returns immediately with EAGAIN/EWOULDBLOCK if buffer is full

The `fcntl()` system call can set or clear the O_NONBLOCK flag on an existing file descriptor using F_SETFL.

## What's Broken
The program attempts to read from a pipe in non-blocking mode but doesn't properly handle the EAGAIN error, causing incorrect behavior.

## Learning Goal
- Understand the difference between blocking and non-blocking I/O
- Learn to use fcntl() to set O_NONBLOCK
- Handle EAGAIN/EWOULDBLOCK errors correctly

## Fix It
Properly handle non-blocking read operations and retry when EAGAIN occurs.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
