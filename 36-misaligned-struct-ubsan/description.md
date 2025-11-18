# Misaligned Struct - Detect with UBSan

## Concept
**UndefinedBehaviorSanitizer (UBSan)** detects undefined behavior at runtime:
- Misaligned memory access
- Signed integer overflow
- Division by zero
- Null pointer dereference
- And many other UB cases

For alignment violations:
- Compiler flag: `-fsanitize=undefined` or `-fsanitize=alignment`
- Detects when a pointer is misaligned for its type
- Reports the exact location and nature of the violation

## What's Broken
The program creates a misaligned pointer to a struct by casting an odd byte offset.

## Learning Goal
Understand that:
- UBSan is a powerful tool for finding undefined behavior
- Alignment violations can be subtle and hard to debug
- `-fsanitize=undefined` catches many UB issues at runtime
- UBSan adds runtime checks (use in development, not production)
- Different from ASan (AddressSanitizer) which focuses on memory errors

## Task
1. Compile without UBSan: `gcc -o broken broken.c`
2. Run: `./broken` (might work, might crash, undefined!)
3. Compile with UBSan: `gcc -fsanitize=undefined -o broken broken.c`
4. Run again and observe the UBSan error report
5. Fix the alignment issue

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
