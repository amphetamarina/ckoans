# Include Search Paths

## Concept
The preprocessor searches for header files in different locations based on include syntax:
- `#include <header.h>`: System include paths (standard library, -I directories)
- `#include "header.h"`: Current directory first, then system paths

Search order for `"header.h"`:
1. Directory containing the current file
2. Directories specified with `-I` flags
3. System include directories

Search order for `<header.h>`:
1. Directories specified with `-I` flags
2. System include directories

## What's Broken
The program tries to include a local header but uses the wrong syntax, causing the compiler to look in the wrong places.

## Learning Goal
Understand:
- Difference between `<>` and `""` for includes
- How the preprocessor searches for header files
- Using `-I` to add include directories

## Task
1. Create the missing header file `myheader.h`
2. Fix the include directive to use the correct syntax
3. Optionally compile with `-I` to demonstrate include paths

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
