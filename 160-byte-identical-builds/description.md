# Produce Byte-Identical Builds

## Concept
A **byte-identical build** (also called bit-for-bit reproducible) means building the same source code twice produces exactly the same binary.

**Verification:**
```bash
# Build 1
make clean && make
sha256sum program > hash1.txt

# Build 2
make clean && make
sha256sum program > hash2.txt

# Compare
diff hash1.txt hash2.txt
```

**Common sources of non-determinism:**
1. **Timestamps**: `__DATE__`, `__TIME__`, file mtimes
2. **Randomness**: ASLR, random seeds, UUIDs
3. **Ordering**: File ordering, symbol ordering
4. **Environment**: Username, hostname, paths
5. **Parallelism**: Race conditions
6. **Optimization**: Non-deterministic optimizations

**Making builds reproducible:**

**1. Fix timestamps:**
```bash
export SOURCE_DATE_EPOCH=1234567890
```

**2. Deterministic tools:**
```bash
ar rcsD lib.a         # Deterministic archive
strip -s binary       # Strip debug info
```

**3. Stable ordering:**
```bash
SRCS = $(sort $(wildcard *.c))
```

**4. Compiler flags:**
```bash
-ffile-prefix-map=OLD=NEW  # Normalize paths
-frandom-seed=0            # Fixed random seed
-fdebug-prefix-map=OLD=NEW # Normalize debug paths
```

**5. Linker flags:**
```bash
-Wl,--build-id=none       # No build ID
-Wl,--hash-style=sysv     # Consistent hash style
```

**Verification tools:**
- `diffoscope`: Deep comparison of binaries
- `strip-nondeterminism`: Remove non-deterministic data

## What's Broken
The program demonstrates reproducible build techniques but has non-deterministic elements.

## Learning Goal
- Achieve byte-identical builds
- Eliminate all sources of non-determinism
- Verify builds with cryptographic hashes
- Understand reproducible build best practices

## Task
1. Identify all sources of non-determinism
2. Apply fixes (timestamps, ordering, flags)
3. Build twice: `make clean && make`
4. Verify: `sha256sum binary` should match
5. Fix remaining issues

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
