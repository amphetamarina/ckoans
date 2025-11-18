# PID, PPID, and PGID

## Concept
Every process in Unix/Linux has three important identifiers:
- **PID (Process ID)**: Unique identifier for the process
- **PPID (Parent Process ID)**: PID of the process that created this process
- **PGID (Process Group ID)**: ID of the process group, used for job control

These can be retrieved using:
- `getpid()` - returns the current process ID
- `getppid()` - returns the parent process ID
- `getpgid(0)` - returns the process group ID of the current process

## What's Broken
The program attempts to display process identifiers, but uses the wrong functions to retrieve them.

## Learning Goal
Understand that:
- Each process has a unique PID assigned by the kernel
- PPID identifies the parent process (usually the shell)
- PGID groups related processes together for job control
- These values are retrieved via specific system calls

## Fix It
Correct the function calls to properly retrieve PID, PPID, and PGID.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
