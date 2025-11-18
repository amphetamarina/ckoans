# Section Headers in Object Files

## Concept
**Section headers** describe the various sections in an object file. Each header contains:

- **Name**: Section name (.text, .data, .bss, .rodata, etc.)
- **Type**: PROGBITS (code/data), NOBITS (.bss), SYMTAB, STRTAB, REL/RELA
- **Flags**: WRITE, ALLOC, EXECINSTR (indicates permissions)
- **Address**: Virtual address when loaded (0 in .o files)
- **Offset**: File offset of section data
- **Size**: Section size in bytes
- **Link/Info**: Additional metadata
- **Alignment**: Required alignment

Use `readelf -S` to inspect section headers.

## What's Broken
The program has variables in different sections. Understanding section headers helps identify where data lives.

## Learning Goal
- Understand what section headers describe
- Learn common section types (.text, .data, .bss, .rodata)
- Inspect sections with `readelf -S`
- Recognize section flags (writable, executable, allocatable)

## Task
1. Compile to object file: `gcc -c broken.c -o broken.o`
2. Inspect section headers: `readelf -S broken.o`
3. Identify which sections contain code vs data
4. Fix the program to produce expected output

## Verify
```bash
gcc -c broken.c -o broken.o
readelf -S broken.o | grep -E '(\.text|\.data|\.bss|\.rodata)'
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
