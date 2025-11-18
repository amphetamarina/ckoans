# Call Stack Layout

## Concept
The **call stack** grows downward (toward lower addresses) on x86-64. Each function call creates a new **stack frame** containing:
- Return address (pushed by `call` instruction)
- Saved frame pointer (if using frame pointers)
- Local variables
- Saved registers
- Function arguments (if they don't fit in registers)

Stack frames are organized in a Last-In-First-Out (LIFO) structure.

## What's Broken
The program attempts to demonstrate stack growth by comparing addresses of local variables in nested function calls, but the comparison logic is incorrect.

## Learning Goal
- Understand that stack grows downward (higher addresses to lower addresses)
- See how nested function calls create stacked frames
- Recognize stack addresses decrease with each nested call

## Fix It
Fix the address comparison to correctly verify stack growth direction.

## Verify
```bash
gcc -O0 -fno-omit-frame-pointer -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
