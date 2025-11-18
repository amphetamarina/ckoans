# Stepping Modes - Navigate Code Line by Line

## Concept
gdb provides multiple ways to step through code:

- **step (s)**: Execute one line, stepping INTO function calls
- **next (n)**: Execute one line, stepping OVER function calls
- **finish**: Execute until current function returns
- **stepi (si)**: Execute one machine instruction
- **nexti (ni)**: Execute one instruction, step over calls
- **until**: Execute until reaching a line number or leaving loop

These commands let you trace execution flow at different granularities.

## What's Broken
The program has a subtle bug in nested function calls. Use stepping to trace the execution flow.

## Learning Goal
- Understand difference between `step` and `next`
- Step into functions to trace execution
- Use `finish` to exit current function
- Navigate loops with `until`

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run in gdb: `gdb ./broken`
3. Set breakpoint at main: `break main`
4. Use `step` to enter functions and `next` to step over
5. Trace the bug through the call chain
6. Fix the calculation error

## Verify
```bash
gcc -g broken.c -o broken
# Example gdb session:
# (gdb) break main
# (gdb) run
# (gdb) next
# (gdb) step  (steps into function)
# (gdb) finish  (return from function)
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
