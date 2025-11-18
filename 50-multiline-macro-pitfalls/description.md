# Multiline Macro Pitfalls

## Concept
Multiline macros use backslash `\` for line continuation. Common pitfalls:

1. **Missing `do { ... } while(0)` wrapper**: Without it, macros break in if-statements
   ```c
   #define BAD(x) foo(x); bar(x)
   if (cond) BAD(y);  // Only foo(y) is conditional!

   #define GOOD(x) do { foo(x); bar(x); } while(0)
   if (cond) GOOD(y);  // Both statements conditional
   ```

2. **Double evaluation**: Arguments evaluated multiple times
   ```c
   #define MAX(a,b) ((a) > (b) ? (a) : (b))
   MAX(x++, y++)  // x or y incremented TWICE!
   ```

3. **Missing semicolons/braces**: Causes unexpected behavior

## What's Broken
The multiline macros have multiple issues: missing do-while wrapper, double evaluation, and incorrect syntax.

## Learning Goal
Understand:
- Why `do { ... } while(0)` is needed for statement-like macros
- Double evaluation problem in macros
- Proper multiline macro syntax

## Fix It
Wrap statement macros in `do-while(0)`, add proper braces and semicolons.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
