# Program Counter and Sequential Execution

## Concept
The **Program Counter (PC)** is a special register that holds the address of the next instruction to execute. After each instruction, the PC automatically increments to point to the following instruction, enabling sequential execution.

## What's Broken
The program attempts to print numbers 1 through 5, but the loop logic is incorrect. The program counter will not advance through the expected sequence of instructions.

## Learning Goal
Understand that:
- Instructions execute sequentially unless explicitly redirected (branches/jumps)
- The PC increments automatically after each instruction
- Loop constructs control the PC to repeat instruction sequences

## Fix It
Correct the loop logic so the program prints numbers 1 through 5.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
