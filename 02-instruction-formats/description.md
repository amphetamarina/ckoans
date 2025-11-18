# Instruction Formats (Load/Store, Branch, Arithmetic)

## Concept
CPU instructions come in different formats:
- **Load/Store**: Move data between memory and registers
- **Arithmetic**: Perform computations (add, subtract, multiply, etc.)
- **Branch**: Conditional/unconditional jumps that change PC

## What's Broken
The code attempts to compute a simple arithmetic expression but has issues with how values are loaded, computed, and stored.

## Learning Goal
Understand the three fundamental instruction categories and how they compose to form programs.

## Fix It
Fix the computation so it correctly calculates: result = (a * 2) + b

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
