# Exec Overlays Process Image

## Concept
The **`exec()`** family of functions replaces the current process image with a new program:
- Loads a new executable into the current process's memory
- **Overlays** the existing code, data, and stack
- Preserves the same PID, but replaces everything else
- **Never returns** on success (the calling code is gone!)
- Only returns (-1) on error

Common variants:
- `execl()` - takes argument list
- `execv()` - takes argument vector (array)
- `execlp()` - searches PATH
- `execve()` - most fundamental, takes environment

## What's Broken
The program has incorrect assumptions about when `exec()` returns and what happens to code after the exec call.

## Learning Goal
Understand that:
- `exec()` replaces the entire process image
- Code after a successful `exec()` never executes
- The process continues with the new program's entry point
- Common pattern: fork() + exec() to run a new program

## Fix It
Fix the logic to properly handle exec's behavior and understand that code after successful exec is unreachable.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
