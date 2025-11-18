# Argument Passing in Registers

## Concept
System V AMD64 ABI argument order:
1. RDI (1st arg)
2. RSI (2nd arg)
3. RDX (3rd arg)
4. RCX (4th arg)
5. R8 (5th arg)
6. R9 (6th arg)
7+ on stack

## What's Broken
Function signature doesn't match calling convention expectations.

## Learning Goal
- Understand register-based argument passing
- See order of arguments in assembly
- Understand stack-based args for >6 parameters

## Task
Fix the argument order.

## Verify
```bash
gcc -S broken.c -o broken.s
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
