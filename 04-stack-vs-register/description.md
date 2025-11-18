# Stack vs Register Machines

## Concept
CPU architectures handle intermediate values differently:
- **Register machines** (x86-64, ARM): Operations on register operands
- **Stack machines** (JVM, old architectures): Push/pop operations
- Modern C compilers target register machines but use stack for spills

## What's Broken
The code has unnecessary complexity that forces register spills to stack.

## Learning Goal
Understand:
- How compilers allocate registers for locals
- When values must "spill" to stack
- Register pressure and optimization

## Fix It
Simplify the computation to reduce register pressure.

## Verify
```bash
gcc -O2 -S broken.c -o broken.s
# Inspect assembly for minimal stack usage
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
