# Build Minimal 3-Instruction Loop

## Concept
A loop requires minimum three instruction types:
1. **Compare/Test**: Check loop condition
2. **Branch**: Conditional jump based on condition
3. **Arithmetic/Load/Store**: Loop body work

## What's Broken
The loop is missing a critical component.

## Learning Goal
Understand the minimal instruction sequence for loops and how the PC jumps backward.

## Fix It
Complete the loop to sum numbers 1 through 10.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
