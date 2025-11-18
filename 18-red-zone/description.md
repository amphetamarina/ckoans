# Red Zone (System V ABI)

## Concept
The **red zone** is a 128-byte region below the stack pointer (RSP) that **leaf functions** can use for temporary storage without adjusting RSP. This is a System V ABI optimization for x86-64.

Key rules:
- Only leaf functions (functions that don't call others) can use it
- Signal handlers and interrupts may clobber it
- Windows x64 ABI does NOT have a red zone
- Kernel code typically disables red zone (`-mno-red-zone`)

## What's Broken
The code incorrectly assumes all functions can use the red zone, but non-leaf functions must not rely on it.

## Learning Goal
- Understand red zone is for leaf functions only
- See when compiler can optimize away stack pointer adjustment
- Recognize ABI-specific stack conventions

## Fix It
Identify which function can safely use the red zone and fix the logic.

## Verify
```bash
gcc -O2 -S broken.c -o broken.s
grep -E '(sub|add).*rsp' broken.s  # See which functions adjust RSP
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
