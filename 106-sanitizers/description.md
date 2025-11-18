# Sanitizers

## Concept
Sanitizers are runtime error detection tools built into GCC and Clang:
- **AddressSanitizer (`-fsanitize=address`)**: Detects memory errors (use-after-free, buffer overflow, etc.)
- **UndefinedBehaviorSanitizer (`-fsanitize=undefined`)**: Detects undefined behavior
- **ThreadSanitizer (`-fsanitize=thread`)**: Detects data races
- **LeakSanitizer**: Detects memory leaks (included with ASan)

Sanitizers add instrumentation to detect errors at runtime with minimal performance overhead.

## What's Broken
The code has multiple bugs that sanitizers will detect.

## Learning Goal
Understand:
- What sanitizers detect
- How to enable and use sanitizers
- Common patterns that trigger sanitizer errors

## Fix It
Fix all issues detected by AddressSanitizer and UndefinedBehaviorSanitizer.

## Verify
```bash
gcc -fsanitize=address,undefined -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
