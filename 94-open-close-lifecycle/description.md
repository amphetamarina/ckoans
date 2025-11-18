# File Descriptor Open/Close Lifecycle

## Concept
A **file descriptor** is a small non-negative integer that represents an open file. The kernel maintains a per-process table of open file descriptors. The lifecycle is:

1. **open()** - Request a new file descriptor from the kernel
2. **read()/write()** - Perform I/O operations using the file descriptor
3. **close()** - Release the file descriptor back to the kernel

Forgetting to close file descriptors causes **resource leaks**. The kernel has a per-process limit (typically 1024 or higher), and exhausting this limit prevents opening new files.

## What's Broken
The program opens files in a loop but fails to properly manage the file descriptor lifecycle, leading to resource exhaustion.

## Learning Goal
- Understand that file descriptors are limited resources
- Learn proper open/close pairing (similar to malloc/free)
- See what happens when file descriptors are leaked

## Fix It
Add proper cleanup to ensure all opened file descriptors are closed.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
