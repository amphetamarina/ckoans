# ASLR Impact

## Concept
**Address Space Layout Randomization (ASLR)** randomizes memory addresses:
- Stack, heap, libraries, and executable base are randomized
- Makes exploitation harder (can't hardcode addresses)
- Enabled by default on modern Linux systems
- Position Independent Executable (PIE) required for full randomization

Impact:
- Addresses differ between runs
- Cannot rely on fixed addresses in code
- Must use relative addressing
- Check with: `cat /proc/sys/kernel/randomize_va_space`
  - 0 = disabled
  - 1 = partial (stack/heap/libs, not executable)
  - 2 = full (includes executable with PIE)

## What's Broken
The program incorrectly assumes addresses are constant across runs.

## Learning Goal
Understand that:
- ASLR randomizes addresses for security
- Addresses change on each program execution
- Never hardcode absolute addresses
- PIE (Position Independent Executable) enables full ASLR
- Compile with `-fPIE -pie` for PIE executable
- Can temporarily disable with `setarch $(uname -m) -R ./program`

## Task
1. Compile with PIE: `gcc -fPIE -pie -o broken broken.c`
2. Run multiple times and observe different addresses
3. Check ASLR status: `cat /proc/sys/kernel/randomize_va_space`

## Verify
```bash
gcc -fPIE -pie -o broken broken.c && ./broken
```
