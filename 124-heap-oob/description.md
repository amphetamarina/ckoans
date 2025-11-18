# Heap Out-of-Bounds - Detect with ASan

## Concept
**Heap out-of-bounds (OOB)** access occurs when reading or writing outside allocated heap memory boundaries. This causes:
- Memory corruption
- Crashes (if accessing unmapped memory)
- Security vulnerabilities

**AddressSanitizer (ASan)** detects heap OOB by:
- Adding red zones around allocations
- Poisoning these red zones
- Trapping any access to poisoned memory

Compile with: `gcc -fsanitize=address -g`

## What's Broken
The program has heap buffer overflows and underflows that ASan will catch.

## Learning Goal
- Understand heap out-of-bounds errors
- Use ASan to detect heap overflow/underflow
- Read ASan error reports showing allocation site and access site
- Fix array indexing bugs

## Task
1. Compile with ASan: `gcc -fsanitize=address -g broken.c -o broken`
2. Run and observe ASan error: `./broken`
3. Read the error report showing the overflow
4. Fix the buffer overflow bugs
5. Compile without ASan and verify correct output

## Verify
```bash
# Should fail with ASan
gcc -fsanitize=address -g broken.c -o broken
./broken 2>&1 | grep -q "heap-buffer-overflow" && echo "ASan detected heap OOB (expected)"

# After fixing, should pass
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
