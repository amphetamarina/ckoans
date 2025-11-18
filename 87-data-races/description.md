# Data Races

## Concept
A **data race** occurs when:
1. Two or more threads access the same memory location
2. At least one access is a write
3. The accesses are not synchronized

**Why it's a problem**:
- Results are non-deterministic
- Depends on thread scheduling and timing
- Can produce corrupted data
- Even simple operations like `x++` are not atomic

**Example**: `counter++` compiles to:
```asm
mov eax, [counter]  ; Read
add eax, 1          ; Modify
mov [counter], eax  ; Write
```
If two threads interleave these instructions, increments can be lost!

**Solutions**:
- **Mutexes** (`pthread_mutex_t`) - Mutual exclusion locks
- **Atomic operations** (`__atomic_*` or C11 `<stdatomic.h>`)
- **Condition variables** - For waiting on conditions
- **Memory barriers** - Enforce ordering

## What's Broken
The program has unprotected shared variable access, causing a data race.

## Learning Goal
Understand that:
- Concurrent writes without synchronization cause races
- Even simple operations need protection
- Race bugs are hard to reproduce and debug
- Proper locking prevents races

## Fix It
Add mutex protection around shared counter increments.

## Verify
```bash
gcc -pthread -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
