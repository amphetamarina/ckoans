# Caller-Saved vs Callee-Saved Registers

## Concept
Calling conventions define register preservation:
- **Caller-saved**: Caller must save before call if needed (RAX, RCX, RDX, RSI, RDI, R8-R11)
- **Callee-saved**: Callee must preserve (RBX, RBP, R12-R15)
- Affects code generation and performance

## What's Broken
Function doesn't preserve callee-saved semantics properly.

## Learning Goal
- Understand register preservation rules
- See prologue/epilogue save/restore
- Understand why some registers are "safe" across calls

## Task
Examine the assembly and fix the logic error.

## Verify
```bash
gcc -O1 -S broken.c -o broken.s
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
