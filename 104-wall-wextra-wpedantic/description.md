# -Wall -Wextra -Wpedantic

## Concept
GCC and Clang provide compiler warning flags to catch common errors and questionable code patterns:
- **`-Wall`**: Enables most common warnings (despite the name, not "all" warnings)
- **`-Wextra`**: Additional warnings beyond `-Wall`
- **`-Wpedantic`**: Warns about non-standard C code

These flags help catch:
- Unused variables
- Missing return values
- Implicit conversions
- Non-portable constructs

## What's Broken
The code compiles without warnings by default but contains several issues that warning flags would catch.

## Learning Goal
Understand:
- Why compiler warnings matter
- What `-Wall -Wextra -Wpedantic` detect
- How to write warning-free code

## Fix It
Fix all issues that would be flagged by `-Wall -Wextra -Wpedantic`.

## Verify
```bash
gcc -Wall -Wextra -Wpedantic -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
