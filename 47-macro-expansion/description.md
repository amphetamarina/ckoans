# Macro Expansion

## Concept
The C **preprocessor** performs textual substitution before compilation. Macros are expanded recursively:
- **Object-like macros**: `#define PI 3.14159`
- **Function-like macros**: `#define MAX(a,b) ((a) > (b) ? (a) : (b))`

Key points:
- Macro expansion is pure text replacement (no type checking)
- Macros expand before the compiler sees the code
- Parentheses are critical to avoid precedence issues

## What's Broken
The macro definitions are incorrect and will produce wrong results due to operator precedence and missing parentheses.

## Learning Goal
Understand:
- How preprocessor macros work as textual substitution
- Why parentheses matter in macro definitions
- Common macro pitfalls (double evaluation, precedence)

## Fix It
Add proper parentheses to macro definitions to ensure correct evaluation order.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
