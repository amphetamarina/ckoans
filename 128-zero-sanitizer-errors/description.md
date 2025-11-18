# Zero Sanitizer Errors - Write Safe Code

## Concept
This koan tests your ability to write code that passes **all sanitizers**:
- **AddressSanitizer (ASan)**: Detects memory errors
- **UndefinedBehaviorSanitizer (UBSan)**: Detects undefined behavior
- **LeakSanitizer (LSan)**: Detects memory leaks (part of ASan)

The goal is to write code with **zero sanitizer errors** - a best practice for production code.

Compile with: `gcc -fsanitize=address,undefined -g`

## What's Broken
The program has multiple types of errors that different sanitizers will catch.

## Learning Goal
- Understand that code can have multiple classes of bugs
- Use multiple sanitizers together
- Write defensive code that avoids common pitfalls
- Verify code safety with comprehensive sanitizer coverage

## Task
1. Compile with all sanitizers: `gcc -fsanitize=address,undefined -g broken.c -o broken`
2. Run and observe all errors: `./broken 2>&1 | less`
3. Fix each error one by one
4. Re-run until all sanitizer errors are gone
5. Verify correct output

## Verify
```bash
# Should fail with sanitizers
gcc -fsanitize=address,undefined -g broken.c -o broken
./broken 2>&1 | grep -E "(ERROR|runtime error)" && echo "Sanitizers detected errors (expected)"

# After fixing, should pass with sanitizers
gcc -fsanitize=address,undefined -g broken.c -o broken
./broken

# And should pass without sanitizers
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
