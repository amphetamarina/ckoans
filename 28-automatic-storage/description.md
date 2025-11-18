# Automatic (Stack) Storage Duration

## Concept
Objects with **automatic storage duration** (local variables) are:
- Allocated on the stack when their scope is entered
- Destroyed when their scope is exited
- Uninitialized by default (contain garbage values)
- Created and destroyed automatically with each function call

## What's Broken
The program uses an uninitialized automatic variable, leading to unpredictable output.

## Learning Goal
Understand that:
- Automatic variables have stack lifetime
- They are NOT automatically initialized (unlike static variables)
- Each function call gets fresh stack space
- Uninitialized variables contain whatever was previously in that memory
- This is undefined behavior and can cause bugs

## Fix It
Initialize the automatic variable to ensure predictable behavior.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
