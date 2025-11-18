# Rebuild cat Using Only Syscalls

## Concept
The `cat` command reads files and writes them to stdout. While normally implemented using stdio functions (fopen, fread, printf), it can be built using only syscalls:

- **open()** - Open the file and get a file descriptor
- **read()** - Read chunks of data from the file descriptor
- **write()** - Write data to stdout (file descriptor 1)
- **close()** - Clean up the file descriptor

This demonstrates that stdio functions are wrappers around lower-level syscalls.

## What's Broken
The program attempts to implement cat using syscalls but has bugs in the file handling logic that prevent it from working correctly.

## Learning Goal
- Understand how to use raw syscalls for file I/O
- Learn the relationship between stdio and syscalls
- Practice proper error handling and resource cleanup

## Fix It
Fix the syscall-based file reading logic to correctly display file contents.

## Verify
```bash
echo "Hello, World!" > /tmp/testfile.txt
echo "This is line 2" >> /tmp/testfile.txt
gcc -o broken broken.c && ./broken /tmp/testfile.txt
diff <(./broken /tmp/testfile.txt) expected.txt
```
