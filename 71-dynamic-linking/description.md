# Dynamic Linking

## Concept
**Dynamic linking** defers symbol resolution to runtime:

- Shared libraries (.so files) are loaded at program startup
- Multiple programs can share the same library in memory
- Smaller executable size (library code not embedded)
- Can update libraries without recompiling programs
- Runtime dependency: program needs the .so file to run

The **dynamic linker** (ld.so or ld-linux.so):
- Loads required shared libraries
- Resolves symbols at runtime
- Handles library versioning

Commands:
- `ldd program` - show shared library dependencies
- `LD_LIBRARY_PATH=/path` - specify library search path
- Compile with `-shared` to create .so files

## What's Broken
The program uses standard library functions (dynamically linked by default). Understanding dynamic linking helps debug runtime library issues.

## Learning Goal
- Understand how dynamic linking works
- Use `ldd` to see library dependencies
- Learn about the dynamic linker
- Understand shared library advantages/disadvantages

## Task
1. Compile normally: `gcc broken.c -o broken` (uses dynamic linking)
2. Check dependencies: `ldd broken`
3. See that libc.so is required
4. Fix the program logic

## Verify
```bash
gcc -o broken broken.c
ldd broken | grep -E '(libc|linux-vdso)'
./broken
diff <(./broken) expected.txt
```
