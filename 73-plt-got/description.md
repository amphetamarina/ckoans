# PLT and GOT

## Concept
The **Procedure Linkage Table (PLT)** and **Global Offset Table (GOT)** enable position-independent code and lazy binding for shared libraries.

**GOT (Global Offset Table):**
- Writable table of addresses
- Contains addresses of global data and functions
- One entry per external symbol
- Updated by dynamic linker at runtime

**PLT (Procedure Linkage Table):**
- Executable code stubs
- Indirects through GOT entries
- Implements lazy binding (on-demand resolution)

**How it works:**
1. First call: PLT → dynamic linker → resolves symbol → updates GOT → jumps to function
2. Later calls: PLT → GOT (now resolved) → function directly

**Lazy binding** (default):
- Symbols resolved on first use
- Faster startup time

**Immediate binding** (`LD_BIND_NOW=1`):
- All symbols resolved at startup
- Slower startup, but predictable timing

## What's Broken
The program calls shared library functions that use PLT/GOT mechanism.

## Learning Goal
- Understand PLT and GOT purpose
- Learn about lazy vs immediate binding
- Inspect PLT/GOT with `objdump` and `readelf`
- See how dynamic linking achieves position independence

## Task
1. Compile: `gcc broken.c -o broken`
2. Inspect PLT: `objdump -d broken | grep -A5 'plt'`
3. Inspect GOT relocations: `readelf -r broken | grep -E '(GOT|printf)'`
4. Fix the program logic

## Verify
```bash
gcc -o broken broken.c
objdump -d broken | grep -E '(<printf@plt>|\.plt)' | head -3
./broken
diff <(./broken) expected.txt
```
