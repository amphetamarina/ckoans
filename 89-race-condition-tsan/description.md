# Race Condition - Detect with TSAN

## Concept
**ThreadSanitizer (TSAN)** is a runtime tool that detects data races in multithreaded programs:

**How it works**:
- Instruments memory accesses at compile time
- Tracks happens-before relationships at runtime
- Detects when two threads access same memory without proper synchronization
- Reports exact locations of conflicting accesses

**Compile with**: `gcc -fsanitize=thread -g -pthread`

**What TSAN detects**:
- Data races (unsynchronized concurrent access)
- Use of uninitialized mutexes
- Thread leaks
- Deadlocks (with `TSAN_OPTIONS=detect_deadlocks=1`)

**TSAN report includes**:
- Location of both conflicting accesses
- Thread IDs involved
- Stack traces showing how each access was reached
- Type of access (read/write)

**Limitations**:
- Runtime overhead (2-20x slower)
- Cannot use with AddressSanitizer simultaneously
- Some false positives possible with lock-free code
- Requires good test coverage to trigger races

## What's Broken
The program has data races that TSAN will detect and report.

## Learning Goal
- Understand what data races are
- Use TSAN to detect races automatically
- Read and interpret TSAN reports
- Fix races with proper synchronization

## Task
1. Compile with TSAN: `gcc -fsanitize=thread -g -pthread broken.c -o broken`
2. Run and observe TSAN warnings: `./broken 2>&1 | grep -q "WARNING: ThreadSanitizer: data race"`
3. Read the error report to find the race
4. Fix by adding proper mutex synchronization
5. Compile without TSAN and verify correct output

## Verify
```bash
# Should fail with TSAN
gcc -fsanitize=thread -g -pthread broken.c -o broken
./broken 2>&1 | grep -q "WARNING: ThreadSanitizer: data race" && echo "TSAN detected data race (expected)"

# After fixing, should pass
gcc -pthread -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
