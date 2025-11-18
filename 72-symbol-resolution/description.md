# Symbol Resolution

## Concept
**Symbol resolution** is how the linker matches symbol references with definitions. Rules:

**Strong vs Weak Symbols:**
- **Strong**: Functions, initialized globals
- **Weak**: Uninitialized globals, symbols marked with `__attribute__((weak))`

**Resolution Rules:**
1. Multiple strong symbols with same name → linker error
2. One strong + weak symbols → choose strong
3. Multiple weak symbols → choose any (usually first)

**Symbol Scope:**
- `static` → file scope only (not visible to linker)
- Default → global scope (visible to linker)
- `extern` → reference to symbol defined elsewhere

**Link Order Matters:**
- For static libraries: `gcc main.o -lmylib` (libraries last)
- Within archives: objects searched in order

## What's Broken
The program has duplicate or conflicting symbol definitions that demonstrate resolution rules.

## Learning Goal
- Understand strong vs weak symbols
- Learn symbol resolution rules
- See how the linker handles duplicate symbols
- Understand the importance of link order

## Task
1. Compile and observe: `gcc broken.c -o broken`
2. Fix symbol conflicts
3. Understand which definition was chosen

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
