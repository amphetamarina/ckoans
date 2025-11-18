# Watchpoints - Break When Data Changes

## Concept
**Watchpoints** pause execution when a variable's value changes, regardless of where the change occurs. This is essential for tracking down memory corruption.

gdb watchpoint commands:
- **watch expr**: Break when expr is written
- **rwatch expr**: Break when expr is read
- **awatch expr**: Break when expr is accessed (read or written)
- **info watchpoints**: List all watchpoints
- **delete N**: Delete watchpoint N

Hardware watchpoints use CPU debug registers for efficiency.

## What's Broken
A variable is being corrupted by an out-of-bounds write. Use a watchpoint to catch when it changes.

## Learning Goal
- Set watchpoints on variables
- Catch unexpected modifications
- Use watchpoints to debug memory corruption
- Understand hardware vs software watchpoints

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run in gdb: `gdb ./broken`
3. Set a watchpoint on the corrupted variable
4. When it triggers, examine the backtrace
5. Find the out-of-bounds write causing corruption

## Verify
```bash
gcc -g broken.c -o broken
# Example gdb session:
# (gdb) break main
# (gdb) run
# (gdb) watch variable_name
# (gdb) continue
# (gdb) backtrace
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
