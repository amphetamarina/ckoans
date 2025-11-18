# Include vs Libs Flags

## Concept
pkg-config provides two types of flags:

**`--cflags`**: Compiler flags (for compilation)
- `-I/path/to/headers` - Add header search path
- `-D` flags for preprocessor definitions
- Used during compilation (`.c` → `.o`)

**`--libs`**: Linker flags (for linking)
- `-L/path/to/libs` - Add library search path
- `-lname` - Link with library
- Used during linking (`.o` → executable)

Common mistakes:
- Using `--libs` during compilation
- Using `--cflags` during linking only
- Wrong order: `-l` must come after `-L`
- Forgetting one or both flags

Correct usage:
```bash
# Compilation
gcc -c $(pkg-config --cflags mylib) file.c -o file.o

# Linking
gcc file.o $(pkg-config --libs mylib) -o program

# All at once
gcc $(pkg-config --cflags mylib) file.c $(pkg-config --libs mylib) -o program
```

## What's Broken
The Makefile confuses `--cflags` and `--libs`, causing compilation or linking failures.

## Learning Goal
Understand:
- When to use `--cflags` vs `--libs`
- Why flag order matters
- How to properly integrate pkg-config into Makefiles

## Fix It
Fix the Makefile to use `--cflags` and `--libs` correctly.

## Verify
```bash
export PKG_CONFIG_PATH=.
make
./program
diff <(./program) expected.txt
```
