# Debug Expansion with gcc -E

## Concept
The `gcc -E` flag stops after preprocessing and outputs the expanded source code. This is invaluable for:
- Debugging macro expansions
- Seeing what the compiler actually compiles
- Understanding header file contents
- Tracing include chains

Output includes:
- All macro expansions performed
- All `#include` files expanded
- Line markers (`# linenum "filename"`) for error reporting
- Comments stripped (unless `-C` flag used)

Usage:
```bash
gcc -E source.c           # Print to stdout
gcc -E source.c -o out.i  # Save to file
gcc -E -P source.c        # No line markers
```

## What's Broken
The program has a macro that expands incorrectly. Use `gcc -E` to see the actual expansion and identify the problem.

## Learning Goal
Understand:
- How to use `gcc -E` to debug preprocessor issues
- Reading preprocessed output
- Identifying macro expansion bugs

## Task
1. Run `gcc -E broken.c` to see the preprocessed output
2. Identify how the macro expands (look for the function body)
3. Fix the macro definition
4. Verify the expansion is correct

## Verify
```bash
gcc -E broken.c | grep -A 5 "main"  # See the expanded code
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
