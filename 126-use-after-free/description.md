# Use-After-Free - Detect with ASan

## Concept
**Use-after-free** occurs when code accesses memory after it has been freed. This is dangerous because:
- The memory may be reused for other allocations
- Reading gives unpredictable values
- Writing corrupts unrelated data
- Security vulnerability (can be exploited)

**AddressSanitizer (ASan)** detects use-after-free by:
- Quarantining freed memory (not immediately reusing it)
- Poisoning freed regions
- Catching any access to freed memory

Compile with: `gcc -fsanitize=address -g`

## What's Broken
The program has use-after-free bugs where pointers are used after memory is freed.

## Learning Goal
- Recognize use-after-free patterns
- Understand why dangling pointers are dangerous
- Use ASan to catch use-after-free at runtime
- Fix by ensuring pointers aren't used after free

## Task
1. Compile with ASan: `gcc -fsanitize=address -g broken.c -o broken`
2. Run and observe ASan error: `./broken`
3. Read the error showing the use site and free site
4. Fix by removing accesses after free or reordering operations
5. Verify correct output

## Verify
```bash
# Should fail with ASan
gcc -fsanitize=address -g broken.c -o broken
./broken 2>&1 | grep -q "heap-use-after-free" && echo "ASan detected UAF (expected)"

# After fixing, should pass
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
