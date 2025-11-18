# Inspect Assembly of a 2-Line C Program

## Concept
Use `gcc -S` to generate assembly output and understand how C translates to machine instructions.

## What's Broken
The program is syntactically correct but you need to inspect its assembly to understand what happens at the CPU level.

## Learning Goal
Learn to:
- Generate assembly with `gcc -S`
- Read basic assembly syntax
- Map C statements to assembly instructions
- Identify function prologue/epilogue

## Task
1. Fix the C program if needed
2. Compile to assembly: `gcc -S broken.c -o broken.s`
3. Examine the assembly
4. Answer: How many instructions does the simple addition generate?

## Verify
```bash
gcc -S broken.c -o broken.s
cat broken.s
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
