# Pipes for Inter-Process Communication

## Concept
A **pipe** is a unidirectional communication channel between processes. The `pipe()` system call creates two file descriptors:

- **pipefd[0]** - Read end of the pipe
- **pipefd[1]** - Write end of the pipe

Data written to pipefd[1] can be read from pipefd[0]. Pipes are commonly used with `fork()` to communicate between parent and child processes.

**Critical**: Unused pipe ends must be closed! If the write end stays open, readers will never see EOF. If the read end stays open, writers may block forever.

## What's Broken
The program uses a pipe to send data from parent to child, but doesn't properly manage which process should close which pipe ends, causing the child to hang waiting for data.

## Learning Goal
- Understand pipe() creates a unidirectional channel
- Learn proper pipe end management after fork()
- See why closing unused ends is critical

## Fix It
Close the appropriate pipe ends in both parent and child processes.

## Verify
```bash
gcc -o broken broken.c && timeout 2 ./broken
diff <(./broken) expected.txt
```
