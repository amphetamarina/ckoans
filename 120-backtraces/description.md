# Backtraces - Examine Call Stack

## Concept
A **backtrace** (or stack trace) shows the chain of function calls leading to the current point. gdb commands:

- **backtrace (bt)**: Show full call stack
- **bt full**: Show stack with local variables
- **frame N (f N)**: Switch to frame N
- **info frame**: Show detailed frame info
- **up/down**: Move up/down the stack
- **info args**: Show function arguments
- **info locals**: Show local variables

Backtraces are crucial for understanding how execution reached a crash or bug.

## What's Broken
The program crashes due to a null pointer dereference. Use backtrace to find the call chain.

## Learning Goal
- Generate and read backtraces
- Navigate stack frames with `frame`, `up`, `down`
- Inspect variables at different stack levels
- Trace bugs through multiple function calls

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run in gdb: `gdb ./broken`
3. When it crashes, use `backtrace` to see the call stack
4. Use `frame` to inspect different stack frames
5. Find which function passes the null pointer

## Verify
```bash
gcc -g broken.c -o broken
# Example gdb session:
# (gdb) run
# (gdb) backtrace
# (gdb) frame 1
# (gdb) info locals
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
