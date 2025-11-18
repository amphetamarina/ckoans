# Parallel Builds

## Concept
Make supports parallel builds with `-j N` (N jobs):
```bash
make -j 4  # Build with 4 parallel jobs
make -j    # Use as many jobs as possible
```

For parallel builds to work correctly:
- Dependencies must be complete and accurate
- Shared resources need proper ordering
- Order-only prerequisites for directories: `target: | dir`
- `.NOTPARALLEL` to disable parallelism for specific targets

Common pitfalls:
- Missing dependencies cause race conditions
- Multiple recipes writing to the same file
- Directory creation races

## What's Broken
The Makefile has missing or incorrect dependencies that cause race conditions during parallel builds.

## Learning Goal
Understand:
- How parallel builds expose dependency bugs
- How to declare proper prerequisites
- When to use order-only prerequisites
- How to debug parallel build failures

## Fix It
Add proper dependencies so `make -j` works reliably.

## Verify
```bash
make clean
make -j4
./program
diff <(./program) expected.txt
```
