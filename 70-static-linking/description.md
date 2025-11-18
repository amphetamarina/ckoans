# Static Linking

## Concept
**Static linking** combines all code into a single executable at link time:

- All library code is copied into the executable
- No runtime dependencies on shared libraries (except libc on most systems)
- Larger executable size
- Faster startup (no dynamic linking overhead)
- Executable is self-contained

Use `-static` flag with gcc to force static linking of all libraries.

**Static libraries** (.a files):
- Archives of .o files created with `ar`
- Linked at compile time
- Only needed functions are extracted and included

Compare:
- `gcc program.c -o program` (dynamic linking, default)
- `gcc -static program.c -o program` (static linking)

## What's Broken
The program needs a static library to link against. You'll create the library and link it properly.

## Learning Goal
- Understand static linking vs dynamic linking
- Learn to create and use static libraries
- Use the `-static` flag
- See the size difference between static and dynamic executables

## Task
1. Compile helper: `gcc -c helper.c -o helper.o`
2. Create static library: `ar rcs libhelper.a helper.o`
3. Link against it: `gcc broken.c -L. -lhelper -o broken`
4. (Optional) Try with `-static` to statically link everything

## Verify
```bash
gcc -c broken.c -o broken.o
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
