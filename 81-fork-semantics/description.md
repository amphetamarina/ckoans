# Fork Semantics

## Concept
**`fork()`** creates a new process by duplicating the calling process. The key semantics are:
- Creates a child process that is a copy of the parent
- Returns **twice**: once in parent, once in child
- In the **parent**: returns child's PID (positive value)
- In the **child**: returns 0
- On **error**: returns -1

After `fork()`:
- Both processes execute the same code from the point of fork
- Child gets a copy of parent's memory, file descriptors, and state
- They execute independently with separate memory spaces

## What's Broken
The program mishandles the return value of `fork()`, leading to incorrect identification of parent and child processes.

## Learning Goal
Understand that:
- `fork()` returns different values to parent and child
- Parent receives child's PID, child receives 0
- Both processes continue execution after the fork call
- You must check fork's return value to distinguish parent from child

## Fix It
Correct the logic to properly identify parent and child processes based on fork's return value.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
