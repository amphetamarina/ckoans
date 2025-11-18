# Break Header Dependency → Diagnose

## Concept
When header dependencies are missing or wrong:
- Changing a header doesn't trigger recompilation
- The build uses stale object files
- The program has old behavior despite header changes

Debugging techniques:
1. Run `make clean && make` to verify from scratch
2. Check if `touch header.h && make` rebuilds
3. Examine `.d` files for dependency lists
4. Use `make -d` for debug output

Common causes:
- Missing `-MMD -MP` flags
- Not including generated `.d` files
- Explicit rules that bypass dependency generation
- Circular dependencies

## What's Broken
The Makefile has a broken header dependency. When you change `api.h`, the build doesn't recognize that `program` needs to be rebuilt.

## Learning Goal
Understand:
- How to diagnose missing dependencies
- How to use `make -d` and `.d` files for debugging
- Why incremental builds fail with missing dependencies

## Fix It
Fix the Makefile so that changing `api.h` triggers the correct rebuilds.

## Verify
```bash
make clean
make
echo '#define API_VERSION "2.0"' > api.h
make  # Should rebuild
./program
diff <(./program) expected.txt
```
