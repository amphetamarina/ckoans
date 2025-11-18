# Locate Entry Point in Hex Dump

## Concept
The **entry point** is the address where program execution begins. It's stored in the ELF header.

**Finding the entry point:**

1. **Get entry point address:**
   ```bash
   readelf -h program | grep Entry
   ```
   Example output: `Entry point address: 0x1060`

2. **Locate in file:**
   - Entry point is a virtual address (where loaded in memory)
   - Need to find corresponding file offset
   - Use program headers to map VA to file offset

3. **View in hex dump:**
   ```bash
   readelf -l program  # Find segment containing entry point
   hexdump -C program  # View raw bytes
   objdump -d program  # Disassemble to see actual instructions
   ```

**ELF header structure (first 64 bytes on x86-64):**
- Offset 0x00: Magic `7f 45 4c 46` (ELF)
- Offset 0x18 (24): Entry point address (8 bytes, little-endian)
- Offset 0x20 (32): Program header offset
- Offset 0x28 (40): Section header offset

**Entry point in different executables:**
- Static executables: Entry is `_start` function
- Dynamic executables: Entry is in dynamic linker or small stub
- `_start` calls `__libc_start_main` which calls `main`

## What's Broken
The program is correct. You'll learn to locate the entry point in the binary.

## Learning Goal
- Understand what the entry point is
- Learn to find it in the ELF header
- Locate it in a hex dump
- Map virtual addresses to file offsets
- See the relationship between headers and raw bytes

## Task
1. Compile: `gcc broken.c -o broken`
2. Find entry point: `readelf -h broken | grep Entry`
3. View hex dump of header: `hexdump -C broken | head -5`
4. See entry point field at offset 0x18 (little-endian)
5. Disassemble entry: `objdump -d broken | grep -A10 '<_start>'`
6. Fix program logic

## Verify
```bash
gcc -o broken broken.c
readelf -h broken | grep Entry
hexdump -C broken | head -3
./broken
diff <(./broken) expected.txt
```
