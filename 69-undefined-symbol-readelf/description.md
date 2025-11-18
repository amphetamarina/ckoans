# Undefined Symbol - Inspect with readelf

## Concept
An **undefined symbol** (UND) in an object file is a symbol that is referenced but not defined in that file. The linker must find the definition elsewhere (in another .o file or library).

In the symbol table:
- **Defined symbols**: Have a section index (.text, .data, etc.)
- **Undefined symbols**: Have section index "UND"
- **Common symbols**: Uninitialized globals (may show as "COM")

When linking fails with "undefined reference", use `readelf -s` to:
1. Confirm the symbol is undefined in the .o file
2. Check if the symbol name is correct (typos, name mangling)
3. Identify what needs to be linked to resolve it

## What's Broken
The program references a function that doesn't exist, causing an undefined symbol error.

## Learning Goal
- Understand what undefined symbols are
- Use `readelf -s` to identify undefined symbols
- Debug linking errors by inspecting symbol tables
- Learn the workflow: compile → inspect → fix → link

## Task
1. Try to compile: `gcc -c broken.c -o broken.o` (succeeds)
2. Inspect symbols: `readelf -s broken.o | grep UND`
3. Try to link: `gcc broken.o -o broken` (fails - undefined reference)
4. Fix the missing function definition
5. Recompile and verify

## Verify
```bash
gcc -c broken.c -o broken.o
readelf -s broken.o | grep -E '(Symbol|UND)'
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
