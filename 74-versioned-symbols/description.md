# Versioned Symbols

## Concept
**Symbol versioning** allows multiple versions of the same symbol to coexist in a shared library, enabling backward compatibility.

**Why versioning?**
- Library updates can change function signatures
- Old programs need old symbol versions
- New programs use new symbol versions
- Both work with the same .so file

**Example:**
- `memcpy@GLIBC_2.2.5` - old version
- `memcpy@GLIBC_2.14` - new optimized version

**Version Scripts:**
- Define which symbols are exported and their versions
- Control symbol visibility
- Manage ABI compatibility

**Tools:**
- `objdump -T` - show dynamic symbols with versions
- `readelf --dyn-syms` - display versioned symbols
- `nm -D` - list dynamic symbols

**Version dependencies:**
- Programs record which symbol versions they need
- Dynamic linker ensures compatible versions at runtime

## What's Broken
The program demonstrates symbol versioning concepts. You'll inspect versioned symbols in standard libraries.

## Learning Goal
- Understand why symbol versioning exists
- Learn to inspect symbol versions with `objdump -T`
- See version information in dynamic symbols
- Understand backward compatibility mechanisms

## Task
1. Compile: `gcc broken.c -o broken`
2. Check symbol versions: `objdump -T broken | grep GLIBC`
3. See what version of printf/malloc your program uses
4. Fix the program logic

## Verify
```bash
gcc -o broken broken.c
objdump -T broken | grep -E '(GLIBC|printf)' | head -3
./broken
diff <(./broken) expected.txt
```
