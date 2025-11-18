# Stack Out-of-Bounds - Detect with ASan

## Concept
**Stack out-of-bounds (OOB)** access occurs when reading or writing outside stack-allocated array boundaries. This causes:
- Stack corruption
- Overwriting local variables
- Overwriting return addresses (potential security vulnerability)

**AddressSanitizer (ASan)** detects stack OOB by:
- Adding red zones around stack variables
- Poisoning these red zones
- Catching accesses to red zones

Compile with: `gcc -fsanitize=address -g`

## What's Broken
The program has stack buffer overflows that corrupt adjacent variables.

## Learning Goal
- Understand stack buffer overflow
- See how stack OOB can corrupt other variables
- Use ASan to detect stack buffer overflow
- Fix array bounds errors in stack-allocated buffers

## Task
1. Compile with ASan: `gcc -fsanitize=address -g broken.c -o broken`
2. Run and observe ASan error: `./broken`
3. Note the stack-buffer-overflow error
4. Fix the indexing bugs
5. Verify correct output without ASan

## Verify
```bash
# Should fail with ASan
gcc -fsanitize=address -g broken.c -o broken
./broken 2>&1 | grep -q "stack-buffer-overflow" && echo "ASan detected stack OOB (expected)"

# After fixing, should pass
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
