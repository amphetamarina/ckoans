# Return Value Register

## Concept
Functions return values in specific registers:
- Integer/pointer returns: RAX
- Floating-point returns: XMM0
- Larger structures may use memory

## What's Broken
Function return mechanism is incomplete.

## Learning Goal
- Understand RAX as return register
- See how return values flow through registers
- Understand return value optimization

## Task
Fix the return statement.

## Verify
```bash
gcc -S broken.c -o broken.s
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
