# Symbol Table in Object Files

## Concept
The **symbol table** in an object file contains information about all symbols (functions, global variables, etc.) defined in or referenced by the object file. Each entry includes:

- **Symbol name**: The identifier (e.g., function or variable name)
- **Value/Address**: Memory address or offset
- **Size**: Size of the object in bytes
- **Type**: FUNC (function), OBJECT (variable), NOTYPE, etc.
- **Binding**: LOCAL, GLOBAL, WEAK
- **Section**: Which section contains the symbol (.text, .data, .bss, etc.)

Use `nm` or `readelf -s` to inspect the symbol table.

## What's Broken
The program defines symbols but one is missing the proper visibility, preventing it from being seen by the linker.

## Learning Goal
- Understand what information the symbol table contains
- Learn to inspect symbol tables with `nm` and `readelf`
- Recognize the difference between static (local) and global symbols
- See how symbol visibility affects linking

## Task
1. Compile to object file: `gcc -c broken.c -o broken.o`
2. Inspect symbols: `nm broken.o` or `readelf -s broken.o`
3. Fix the visibility issue so all functions appear correctly
4. Verify the program runs and produces expected output

## Verify
```bash
gcc -c broken.c -o broken.o
nm broken.o | grep -E '(compute_sum|main)'
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
