# Broken Macro - Trace Expansion

## Concept
Complex macros can have subtle bugs. To debug them, trace the expansion step by step:

1. **Manual expansion**: Substitute macro arguments mentally/on paper
2. **Use `gcc -E`**: See actual preprocessed output
3. **Add debug prints**: Temporarily print macro arguments
4. **Check precedence**: Ensure proper parenthesization

Common macro bugs:
- Missing parentheses around parameters
- Missing parentheses around whole expression
- Double evaluation of arguments
- Incorrect operator precedence
- Off-by-one errors in formulas

## What's Broken
The program uses macros that produce incorrect results. Use systematic debugging to trace the expansion and find the bugs.

## Learning Goal
Understand:
- How to systematically debug macro issues
- Manual macro expansion technique
- Using `gcc -E` to verify expansions
- Common macro bug patterns

## Task
1. Identify which macro results are wrong
2. Use `gcc -E` to see how macros expand
3. Trace the expansion manually
4. Fix the macro definitions

## Verify
```bash
gcc -E broken.c > expanded.c  # Optional: examine expansion
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
