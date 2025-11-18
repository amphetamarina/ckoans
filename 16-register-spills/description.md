# Register Spills

## Concept
When a function needs more variables than available registers, the compiler **spills** values to the stack. Additionally, callee-saved registers must be preserved across function calls by saving them to the stack in the prologue and restoring them in the epilogue.

Register spills happen when:
- Too many live variables exceed available registers
- Variables have their address taken (must reside in memory)
- Function calls require saving callee-saved registers

## What's Broken
The function uses many local variables but has incorrect computation. Understanding register pressure helps debug such issues.

## Learning Goal
- Understand when values spill from registers to stack
- See relationship between variable count and register availability
- Recognize that taking addresses forces stack allocation

## Fix It
Fix the computation to correctly sum all values.

## Verify
```bash
gcc -O0 -fno-omit-frame-pointer -S broken.c -o broken.s
grep -E 'mov.*-[0-9]+\(%rbp\)' broken.s  # See stack offsets for locals
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
