# Inspect Stack Using gdb info frame

## Concept
GDB provides powerful commands to inspect stack frames:
- `info frame` - Shows current frame details (SP, FP, return address, saved registers)
- `info args` - Shows function arguments
- `info locals` - Shows local variables
- `backtrace` (bt) - Shows call stack
- `frame N` - Switch to frame N

These commands reveal the stack layout and help debug function call issues.

## What's Broken
The program has a function that computes incorrectly. Use gdb to inspect the stack frame and identify the bug.

## Learning Goal
- Use `info frame` to examine stack frame structure
- Inspect local variables and arguments with gdb
- Understand relationship between frame layout and variable values

## Task
1. Compile with debug symbols: `gcc -g -O0 -fno-omit-frame-pointer broken.c -o broken`
2. Run in gdb and set breakpoint: `gdb ./broken`
3. Use: `break buggy_calc`, `run`, `info frame`, `info locals`, `info args`
4. Identify the bug in the calculation
5. Fix the code

## Verify
```bash
gcc -g -O0 -fno-omit-frame-pointer broken.c -o broken
# Manual gdb inspection, then fix and test:
gcc broken.c -o broken && ./broken
diff <(./broken) expected.txt
```
