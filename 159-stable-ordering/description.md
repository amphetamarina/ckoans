# Stable Ordering

## Concept
**Non-deterministic ordering** of inputs can make builds non-reproducible. Stable, deterministic ordering is essential.

**Sources of unstable ordering:**
1. **Filesystem readdir()** - order depends on filesystem
2. **Hash table iteration** - order depends on hash function/ASLR
3. **Parallel builds** - race conditions
4. **Wildcard expansion** - shell-dependent ordering
5. **Linker input order** - affects output layout

**Making ordering stable:**

**Glob patterns:**
```bash
# Unstable (depends on readdir):
gcc *.c -o program

# Stable (sorted):
gcc $(ls *.c | sort) -o program
```

**Build systems:**
```makefile
# Unstable:
SRCS := $(wildcard *.c)

# Stable:
SRCS := $(sort $(wildcard *.c))
```

**Linker scripts:**
```ld
# Stable section ordering
.text : {
    *(.text.startup)
    *(.text.hot)
    *(.text)
    *(.text.*)
}
```

**CMake:**
```cmake
file(GLOB SRCS "*.c")
list(SORT SRCS)  # Ensure stable order
```

## What's Broken
The program demonstrates file processing with unstable ordering.

## Learning Goal
- Understand sources of ordering non-determinism
- Sort inputs before processing
- Use stable ordering in build systems
- Verify ordering doesn't affect output

## Task
1. Identify unstable ordering sources
2. Sort inputs explicitly
3. Verify: Process files in different orders, compare output
4. Fix ordering issues

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
