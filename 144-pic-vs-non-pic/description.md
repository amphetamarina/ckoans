# PIC vs non-PIC

## Concept
**Position Independent Code (PIC)** is code that can execute correctly regardless of its absolute address in memory.

**PIC code:**
- Required for shared libraries
- Uses relative addressing and GOT/PLT
- Compiled with `-fPIC` or `-fPIE`
- Slightly slower (extra indirection)
- Enables ASLR and code sharing

**Non-PIC code:**
- Uses absolute addresses
- Faster (direct addressing)
- Cannot be shared between processes
- Requires text relocations (security risk)

**Key differences:**
- PIC: References go through GOT → can be relocated
- Non-PIC: Direct absolute addresses → fixed location

**Checking:**
- `readelf -d lib.so | grep TEXTREL` → shows text relocations (non-PIC)
- `objdump -d lib.so` → look for GOT/PLT references (PIC)

## What's Broken
The program attempts to create a shared library but uses non-PIC code, which will fail or require text relocations.

## Learning Goal
- Understand why shared libraries require PIC
- Learn the `-fPIC` flag
- See the performance vs security tradeoff
- Recognize text relocation warnings

## Task
1. Compile object with PIC: `gcc -fPIC -c broken.c -o broken.o`
2. Create shared library: `gcc -shared broken.o -o libbroken.so`
3. Check for text relocations: `readelf -d libbroken.so | grep TEXTREL`
4. Fix the code to demonstrate PIC concepts

## Verify
```bash
gcc -fPIC -c broken.c -o broken.o
gcc broken.c -o broken
./broken
diff <(./broken) expected.txt
```
