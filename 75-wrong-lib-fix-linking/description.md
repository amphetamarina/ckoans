# Wrong -l Flag - Fix Linking Failure

## Concept
The `-l` flag tells the linker which libraries to link against:

**Syntax:**
- `-lm` → link against libm.so (math library)
- `-lpthread` → link against libpthread.so (POSIX threads)
- `-lrt` → link against librt.so (real-time extensions)

**How it works:**
- Linker searches for `lib<name>.so` or `lib<name>.a`
- Search paths: `/usr/lib`, `/lib`, paths in `LD_LIBRARY_PATH`
- Order matters: libraries should come after objects that use them

**Common errors:**
```
undefined reference to `sqrt'  → need -lm
undefined reference to `pthread_create'  → need -lpthread
undefined reference to `clock_gettime'  → need -lrt (older systems)
```

**Debug linking:**
- Read error message for function name
- Search which library provides it: `man <function>` or search online
- Add appropriate `-l` flag

## What's Broken
The program uses math functions but doesn't link the math library, causing link failure.

## Learning Goal
- Understand the `-l` flag syntax
- Learn to diagnose missing library errors
- Know common libraries and their flags
- Understand link order

## Task
1. Try to compile: `gcc broken.c -o broken` (fails!)
2. Read error: "undefined reference to sqrt"
3. Fix by adding `-lm`: `gcc broken.c -lm -o broken`
4. Verify program runs correctly

## Verify
```bash
# This will fail initially:
# gcc broken.c -o broken
# Add -lm to fix:
gcc broken.c -lm -o broken && ./broken
diff <(./broken) expected.txt
```
