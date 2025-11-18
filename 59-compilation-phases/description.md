# Compilation Phases

## Concept
C compilation has multiple phases (traditional model):

1. **Preprocessing**: Handle directives (`#include`, `#define`, etc.)
   - Input: `file.c` → Output: `file.i` (expanded source)
   - Tool: `gcc -E`

2. **Compilation**: Convert C to assembly
   - Input: `file.i` → Output: `file.s` (assembly)
   - Tool: `gcc -S`

3. **Assembly**: Convert assembly to object code
   - Input: `file.s` → Output: `file.o` (object file)
   - Tool: `gcc -c` or `as`

4. **Linking**: Combine object files and libraries into executable
   - Input: `file.o` + libraries → Output: `a.out` or `executable`
   - Tool: `gcc` or `ld`

Intermediate files:
- `.i` - Preprocessed source (after `gcc -E`)
- `.s` - Assembly source (after `gcc -S`)
- `.o` - Object file (after `gcc -c`)

## What's Broken
The code needs to be compiled in stages to demonstrate each phase. Fix any issues that appear at different compilation stages.

## Learning Goal
Understand:
- The four main compilation phases
- Intermediate file formats
- Using gcc flags to stop at each phase

## Task
1. Preprocess: `gcc -E broken.c -o broken.i`
2. Compile to assembly: `gcc -S broken.c`
3. Assemble to object: `gcc -c broken.c`
4. Link to executable: `gcc -o broken broken.c`
5. Identify which phase catches errors (if any)

## Verify
```bash
gcc -E broken.c -o broken.i && echo "Preprocessing OK"
gcc -S broken.c && echo "Compilation OK"
gcc -c broken.c && echo "Assembly OK"
gcc -o broken broken.c && echo "Linking OK"
./broken
diff <(./broken) expected.txt
```
