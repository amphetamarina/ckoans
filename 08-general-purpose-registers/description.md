# General-Purpose Registers

## Concept
CPUs have a limited set of general-purpose registers (GPRs):
- x86-64: RAX, RBX, RCX, RDX, RSI, RDI, R8-R15
- Each register can hold integers, addresses, or intermediate values
- Registers are the fastest storage location

## What's Broken
Understanding register allocation by examining generated assembly.

## Learning Goal
- Identify registers in assembly
- Understand register usage patterns
- See how compilers allocate registers

## Task
Fix the program and examine assembly to see register usage.

## Verify
```bash
gcc -O1 -S broken.c -o broken.s
cat broken.s
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
