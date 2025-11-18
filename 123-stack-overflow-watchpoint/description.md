# Stack Overflow - Catch with Watchpoint

## Concept
A **stack overflow** occurs when:
- Recursive functions don't terminate (infinite recursion)
- Large local arrays exceed stack size
- Deep call chains exhaust stack space

Stack overflow typically causes **segmentation fault** when the stack pointer moves into unmapped memory or guard pages.

Use watchpoints or breakpoints to catch the overflow before the crash.

## What's Broken
The program has infinite recursion causing stack overflow. Use gdb to catch it.

## Learning Goal
- Identify stack overflow from symptoms
- Use backtrace to see deep recursion
- Set breakpoint in recursive function to count depth
- Fix the base case to prevent infinite recursion

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run in gdb: `gdb ./broken`
3. When it segfaults, use `backtrace` (may be very long)
4. Use `break` + condition to detect deep recursion
5. Find the missing or incorrect base case

## Verify
```bash
gcc -g broken.c -o broken
# Example gdb session:
# (gdb) run
# (gdb) backtrace 20  (show top 20 frames)
# (gdb) break recursive_function
# (gdb) commands
# > silent
# > printf "Depth exceeded\n"
# > quit
# > end
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
