# Use-After-Free - Detect with ASan

## Concept
**Use-after-free** is accessing memory after it has been freed. This is undefined behavior that can cause:
- Crashes (if memory is unmapped)
- Corruption (if memory is reused)
- Security vulnerabilities (exploitable in some cases)

**AddressSanitizer (ASan)** detects use-after-free by:
- Poisoning freed memory regions
- Maintaining shadow memory to track allocation state
- Catching accesses to poisoned regions

Compile with: `gcc -fsanitize=address -g`

## What's Broken
The program has use-after-free bugs that ASan will catch.

## Learning Goal
- Understand use-after-free vulnerability
- Use ASan to detect and locate the bug
- See ASan's detailed error reports with stack traces

## Task
1. Compile with ASan: `gcc -fsanitize=address -g broken.c -o broken`
2. Run and observe ASan error: `./broken`
3. Read the error report to find the use-after-free
4. Fix by removing accesses to freed memory
5. Compile without ASan and verify correct output

## Verify
```bash
# Should fail with ASan
gcc -fsanitize=address -g broken.c -o broken
./broken 2>&1 | grep -q "heap-use-after-free" && echo "ASan detected use-after-free (expected)"

# After fixing, should pass
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
