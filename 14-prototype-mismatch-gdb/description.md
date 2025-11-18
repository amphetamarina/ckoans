# Prototype Mismatch - Dissect Crash in gdb

## Concept
Calling a function with wrong signature causes:
- Arguments in wrong registers
- Stack misalignment
- Undefined behavior / crashes

## What's Broken
Function declaration doesn't match definition.

## Learning Goal
- Use gdb to diagnose crash
- Understand calling convention violations
- See register state at crash

## Task
1. Compile with `-g`: `gcc -g broken.c -o broken`
2. Run in gdb: `gdb ./broken`
3. Identify the mismatch
4. Fix the function signature

## Verify
```bash
gcc -g broken.c -o broken
gdb -batch -ex run -ex bt ./broken 2>&1 || true
gcc broken.c -o broken && ./broken
diff <(./broken) expected.txt
```
