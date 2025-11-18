# Symbol Visibility

## Concept
**Symbol visibility** controls which symbols are exported from a shared library.

**Visibility levels:**
- `default`: Symbol is visible to other libraries/executables
- `hidden`: Symbol is not visible outside the library
- `protected`: Symbol is visible but cannot be overridden
- `internal`: Like hidden, but with additional constraints

**Why control visibility:**
- Reduces symbol pollution
- Faster dynamic linking (fewer symbols to resolve)
- Prevents accidental API misuse
- Enables better optimization
- Reduces library size

**Methods to control:**
1. Attribute: `__attribute__((visibility("hidden")))`
2. Compiler flag: `-fvisibility=hidden` (default hidden, mark public explicitly)
3. Version script: Control visibility at link time

**Checking visibility:**
```bash
nm -D libfoo.so  # Dynamic symbols only
readelf -s libfoo.so | grep HIDDEN
```

## What's Broken
The library exposes internal implementation details that should be hidden.

## Learning Goal
- Understand symbol visibility in shared libraries
- Learn to mark symbols as hidden/visible
- See the benefits of hiding internal symbols
- Use nm/readelf to inspect symbol visibility

## Task
1. Compile with visibility control: `gcc -fPIC -fvisibility=hidden -c broken.c`
2. Mark public API with `__attribute__((visibility("default")))`
3. Check symbols: `nm -D libbroken.so | grep -E '(public|internal)'`
4. Fix the visibility annotations

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
