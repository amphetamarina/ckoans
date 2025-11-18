# Common Relocation Types

## Concept
**Relocations** are instructions for the linker to patch addresses in object files. Common relocation types on x86-64 include:

- **R_X86_64_PC32**: PC-relative 32-bit (for function calls, IP-relative addressing)
- **R_X86_64_32**: Absolute 32-bit address
- **R_X86_64_64**: Absolute 64-bit address
- **R_X86_64_PLT32**: 32-bit PC-relative offset to PLT entry
- **R_X86_64_GOTPCREL**: PC-relative offset to GOT entry

Relocations allow object files to reference symbols whose final addresses are unknown until linking. Use `readelf -r` or `objdump -dr` to inspect relocations.

## What's Broken
The program references an external variable and function. You'll see relocations in the object file that need to be resolved.

## Learning Goal
- Understand what relocations are and why they're needed
- Learn to inspect relocations with `readelf -r`
- Recognize common relocation types (PC-relative vs absolute)
- See how the linker resolves relocations

## Task
1. Compile to object file: `gcc -c broken.c -o broken.o`
2. Inspect relocations: `readelf -r broken.o`
3. Observe relocation types for function calls and variable access
4. Fix the code to produce the expected output

## Verify
```bash
gcc -c broken.c -o broken.o
readelf -r broken.o | grep -E '(Relocation|OFFSET)'
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
