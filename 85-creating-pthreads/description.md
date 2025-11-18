# Creating Pthreads

## Concept
**POSIX threads (pthreads)** provide multithreading within a single process:

**Key functions**:
- `pthread_create(&thread, attr, function, arg)` - Creates a new thread
  - `thread`: Output parameter for thread ID
  - `attr`: Thread attributes (NULL for defaults)
  - `function`: Entry point (must return `void*` and take `void*`)
  - `arg`: Argument passed to thread function

- `pthread_join(thread, &retval)` - Waits for thread to terminate
  - Blocks until specified thread exits
  - Retrieves return value
  - Must be called to avoid resource leaks

**Unlike fork()**:
- Threads share the same address space
- Lighter weight than processes
- Share global variables, heap, file descriptors
- Have separate stacks

## What's Broken
The program has incorrect pthread function signatures and missing join calls.

## Learning Goal
Understand that:
- Thread functions must match signature: `void* func(void*)`
- Must join threads to reclaim resources
- `pthread_create` returns 0 on success, error code on failure
- Need to link with `-lpthread`

## Fix It
Correct the thread function signature and add proper pthread_join calls.

## Verify
```bash
gcc -pthread -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
