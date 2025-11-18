# Breakpoints - Stop Execution at Specific Points

## Concept
**Breakpoints** allow you to pause program execution at specific locations to inspect state. gdb supports:

- **Line breakpoints**: `break file.c:10` or `break function_name`
- **Conditional breakpoints**: `break line if condition`
- **Temporary breakpoints**: `tbreak` (deleted after first hit)
- **List breakpoints**: `info breakpoints`
- **Delete breakpoints**: `delete N` or `clear function_name`

Breakpoints are essential for examining program state at critical points.

## What's Broken
The program has logic bugs. Use breakpoints to find where values diverge from expectations.

## Learning Goal
- Set breakpoints at functions and line numbers
- Use conditional breakpoints to stop only when conditions are met
- Inspect variables at breakpoints with `print` and `display`
- Continue execution with `continue`

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run in gdb: `gdb ./broken`
3. Set breakpoints at key functions: `break calculate_sum`, `break main`
4. Run and inspect variables: `run`, `print variable_name`
5. Find the logic errors and fix them

## Verify
```bash
gcc -g broken.c -o broken
# Example gdb session:
# (gdb) break calculate_sum
# (gdb) run
# (gdb) print n
# (gdb) continue
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
