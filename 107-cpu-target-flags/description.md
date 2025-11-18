# CPU-Target Flags

## Concept
GCC allows targeting specific CPU architectures and features:
- **`-march=ARCH`**: Generate code for specific architecture (may not run on older CPUs)
- **`-mtune=CPU`**: Optimize for specific CPU (still runs on others)
- **`-m32` / `-m64`**: Target 32-bit or 64-bit
- **`-msse`, `-mavx`, etc.**: Enable specific instruction sets

Key differences:
- `-march=native`: Use all features of the build machine
- `-mtune=native`: Optimize for build machine but maintain compatibility
- Feature flags enable specific CPU instructions (SSE, AVX, etc.)

## What's Broken
The code tries to use CPU features that aren't enabled, causing compilation errors or runtime issues.

## Learning Goal
Understand:
- How to target specific CPU features
- Difference between `-march` and `-mtune`
- How to write portable vs optimized code

## Fix It
Enable the necessary CPU features or write portable code that checks for feature availability.

## Verify
```bash
gcc -march=native -O2 -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
