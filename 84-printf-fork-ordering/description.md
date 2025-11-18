# Printf Before/After Fork - Output Ordering

## Concept
The interaction between **printf buffering** and **fork** can produce surprising output:

**Buffering modes**:
- **Line-buffered** (stdout to terminal): Flushes on newline
- **Fully-buffered** (stdout to file/pipe): Flushes when buffer fills

**Key insight**: When `fork()` is called:
- Child inherits a **copy** of parent's stdio buffers
- If buffer contains unflushed data, it gets duplicated
- Both parent and child may flush the same data

**Example**:
```c
printf("Hello");  // No newline - stays in buffer
fork();           // Buffer copied to child
// Both processes now have "Hello" in their buffer
// Both will flush it → "Hello" appears twice!
```

## What's Broken
The program's printf calls before fork cause duplicated output due to buffering.

## Learning Goal
Understand that:
- stdio uses buffering for efficiency
- `fork()` duplicates the entire process state, including buffers
- Unflushed output before fork will appear multiple times
- Use `fflush(stdout)` before fork to prevent duplication
- Newlines trigger flushing when line-buffered

## Fix It
Add appropriate `fflush()` calls or newlines to control output ordering.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
