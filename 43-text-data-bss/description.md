# .text / .data / .bss Sections

## Concept
The three main sections in an executable:

**.text** (code section):
- Contains executable instructions
- Read-only + executable permissions
- Functions and code reside here

**.data** (initialized data):
- Contains initialized global/static variables
- Read-write permissions
- Takes space in the executable file

**.bss** (uninitialized data):
- Contains uninitialized global/static variables
- Zero-initialized at load time
- Does NOT take space in file (just a size marker)
- Stands for "Block Started by Symbol"

## What's Broken
The program doesn't correctly distinguish between .data and .bss placement.

## Learning Goal
Understand that:
- `.text` = code, `.data` = initialized globals, `.bss` = uninitialized globals
- `.bss` saves file size (zeros don't need storage)
- Static variables go in `.data` or `.bss`, not on stack
- Use `size` command to see section sizes
- Local variables are NOT in these sections (they're on stack/registers)

## Task
1. Compile: `gcc -o broken broken.c`
2. Check sizes: `size broken`
3. View sections: `objdump -h broken | grep -E 'text|data|bss'`

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
