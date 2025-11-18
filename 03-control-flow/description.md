# Control Flow: Jumps, Calls, Returns

## Concept
Control flow instructions alter the program counter (PC) non-sequentially:
- **Jumps**: Unconditional PC modification (goto, unconditional branches)
- **Calls**: Save return address, jump to function
- **Returns**: Restore PC from saved return address

## What's Broken
The function call mechanism is broken - the return value isn't properly computed and returned.

## Learning Goal
Understand how function calls:
1. Push return address onto stack
2. Jump to function address
3. Execute function body
4. Return to caller using saved address

## Fix It
Fix the function to correctly compute and return the sum.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
