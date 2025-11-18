# Shared Memory Semantics in Threads

## Concept
Threads within a process **share the same address space**, meaning:

**Shared between threads**:
- Global variables
- Static variables
- Heap memory (malloc'd data)
- File descriptors
- Code (text) segment

**Private to each thread**:
- Local variables (on thread's stack)
- Function arguments (on thread's stack)
- Thread ID
- Register state
- Stack pointer

**Implications**:
- Threads can communicate via shared memory
- No need for IPC mechanisms like pipes
- But requires synchronization (mutexes, semaphores)
- Races possible when accessing shared data

**Contrast with processes**:
- Processes get separate memory spaces
- fork() creates copies, not shared memory
- Processes need explicit IPC (pipes, shared memory segments)

## What's Broken
The program has incorrect assumptions about what is shared vs. private between threads.

## Learning Goal
Understand that:
- Global variables are visible to all threads
- Each thread has its own stack for local variables
- Modifying shared data requires synchronization
- Stack variables are thread-private

## Fix It
Correct the program to properly distinguish shared globals from thread-local stack variables.

## Verify
```bash
gcc -pthread -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
