# ET_EXEC vs ET_DYN

## Concept
ELF executables have different types, visible in the ELF header:

**ET_EXEC** (Executable):
- Traditional static position executable
- Fixed load address (not position-independent)
- Base address hardcoded at link time
- Cannot be moved (incompatible with ASLR)
- Created with: `gcc -no-pie program.c`

**ET_DYN** (Shared Object/Position-Independent):
- Position-Independent Executable (PIE)
- Can be loaded at any address
- Enables ASLR (Address Space Layout Randomization)
- Modern default on most systems
- Works like a shared library with entry point
- Created with: `gcc -pie program.c` (or default gcc)

**Why PIE/ET_DYN is preferred:**
- Security: ASLR makes exploitation harder
- Flexibility: Kernel can choose load address
- Consistency: Same code generation as shared libraries

**Trade-offs:**
- PIE: Slight performance cost (extra indirection)
- ET_EXEC: Faster but no ASLR

**Check type:**
- `readelf -h file | grep Type`
- `file file` (shows "LSB pie executable" vs "LSB executable")

## What's Broken
The program is correct. You'll compile it both ways and observe the difference.

## Learning Goal
- Understand ET_EXEC vs ET_DYN
- Learn about position-independent executables (PIE)
- See how ASLR relates to executable types
- Compare with `-pie` vs `-no-pie`

## Task
1. Compile as PIE (default): `gcc broken.c -o broken-pie`
2. Check type: `readelf -h broken-pie | grep Type` → ET_DYN
3. Compile as EXEC: `gcc -no-pie broken.c -o broken-exec`
4. Check type: `readelf -h broken-exec | grep Type` → ET_EXEC
5. Fix program logic

## Verify
```bash
gcc -o broken broken.c
readelf -h broken | grep Type
./broken
diff <(./broken) expected.txt
```
