# Deterministic Archives

## Concept
**Static libraries (.a files)** are archives created by `ar`. By default, they embed timestamps and other metadata that prevent reproducible builds.

**Archive metadata:**
- File modification times
- User ID / Group ID
- File permissions
- Member ordering

**Non-deterministic archive:**
```bash
ar rcs libfoo.a file1.o file2.o
# Embeds current timestamp, uid, gid
```

**Deterministic archive:**
```bash
ar rcsD libfoo.a file1.o file2.o  # -D for deterministic
# Or:
ar rcsDU libfoo.a file1.o file2.o  # -U to zero uid/gid
```

**GNU ar flags:**
- `r`: Insert/replace files
- `c`: Create archive
- `s`: Create symbol index
- `D`: Deterministic mode (zero timestamps, uid, gid)
- `U`: Use zero for uid/gid/mode

**Inspecting archive:**
```bash
ar tv libfoo.a      # List with metadata
ar p libfoo.a       # Extract to stdout
```

**Alternatives:**
- `llvm-ar` (deterministic by default in newer versions)
- Post-process with `strip-nondeterminism`

## What's Broken
The program demonstrates archive creation but doesn't use deterministic mode.

## Learning Goal
- Understand archive metadata
- Use deterministic ar flags (-D)
- Create reproducible static libraries
- Verify archives are byte-identical

## Task
1. Create object files: `gcc -c file.c -o file.o`
2. Create archive deterministically: `ar rcsD lib.a file.o`
3. Verify: `ar tv lib.a` (check timestamps)
4. Compare: Build twice, compare with `sha256sum`

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
