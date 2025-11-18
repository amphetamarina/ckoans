# ELF Header

## Concept
The **ELF (Executable and Linkable Format) header** is the first part of an ELF file, containing metadata about the file.

**Key fields:**
- **Magic number**: `7f 45 4c 46` ("\x7fELF") - identifies ELF files
- **Class**: 32-bit (ELFCLASS32) or 64-bit (ELFCLASS64)
- **Data encoding**: Little-endian or big-endian
- **Version**: ELF format version
- **OS/ABI**: Target operating system (Linux, FreeBSD, etc.)
- **Type**: EXEC (executable), DYN (shared object), REL (relocatable), CORE
- **Machine**: Target architecture (x86-64, ARM, etc.)
- **Entry point**: Address where execution begins
- **Program header offset/count**: Location and number of program headers
- **Section header offset/count**: Location and number of section headers

**Inspect with:**
- `readelf -h file` - display ELF header
- `file file` - quick file type identification
- `hexdump -C file | head` - see raw magic bytes

## What's Broken
The program is correct, but you'll inspect its ELF header to understand the format.

## Learning Goal
- Understand ELF header structure
- Learn to inspect headers with `readelf -h`
- Recognize magic bytes and key fields
- See the entry point address

## Task
1. Compile: `gcc broken.c -o broken`
2. Inspect header: `readelf -h broken`
3. Check file type: `file broken`
4. View magic bytes: `hexdump -C broken | head -3`
5. Fix program if needed

## Verify
```bash
gcc -o broken broken.c
readelf -h broken | grep -E '(Magic|Class|Type|Entry)'
./broken
diff <(./broken) expected.txt
```
