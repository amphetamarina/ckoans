# Static vs Dynamic Relocations

## Concept
Relocations can be resolved at different times:

**Static Relocations** (link-time):
- Resolved by the linker when creating the executable
- Used for symbols within the same program
- Address is fixed in the executable
- Example: Calls to functions in the same .o file or static libraries

**Dynamic Relocations** (runtime):
- Resolved by the dynamic linker (ld.so) at program startup
- Used for shared library symbols
- Stored in .rela.dyn or .rela.plt sections
- Example: Calls to printf() in libc.so
- Allows position-independent code (PIC)

Use `readelf -r` on executables to see dynamic relocations.

## What's Broken
The program calls both internal and external functions. Understanding which relocations are static vs dynamic helps debug linking issues.

## Learning Goal
- Understand the difference between static and dynamic relocations
- See when relocations are resolved (link-time vs runtime)
- Inspect dynamic relocations with `readelf -r`
- Understand why shared libraries need dynamic relocations

## Task
1. Compile: `gcc broken.c -o broken`
2. Inspect relocations: `readelf -r broken | grep -E '(printf|internal)'`
3. Note which symbols have dynamic relocations
4. Fix the code to produce expected output

## Verify
```bash
gcc broken.c -o broken
readelf -r broken | grep -E '(Relocation|printf)'
./broken
diff <(./broken) expected.txt
```
