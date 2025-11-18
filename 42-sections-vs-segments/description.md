# Sections vs Segments

## Concept
**Sections** and **segments** are related but different concepts in ELF (Executable and Linkable Format):

**Sections** (linker view):
- `.text`, `.data`, `.bss`, `.rodata`, etc.
- Used during linking
- Viewed with `objdump -h` or `readelf -S`

**Segments** (loader view):
- LOAD, DYNAMIC, INTERP, etc.
- Used at runtime by the loader
- Viewed with `readelf -l`
- Combine multiple sections with similar permissions

Mapping: Multiple sections → one segment (e.g., `.text` + `.rodata` → one read-only segment)

## What's Broken
The program confuses sections with segments.

## Learning Goal
Understand that:
- Sections are for the linker (compile-time)
- Segments are for the loader (runtime)
- `objdump` shows sections
- `readelf -l` shows segments
- Segments group sections by memory permissions
- One segment can contain multiple sections

## Task
1. Compile the program: `gcc -o broken broken.c`
2. View sections: `readelf -S broken | grep -E '\.text|\.data|\.bss'`
3. View segments: `readelf -l broken | grep LOAD`
4. Observe how sections map to segments

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
