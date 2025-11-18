# Zero-Warning Build

## Concept
Professional C projects should compile with zero warnings using strict compiler flags. This practice:
- Catches bugs early
- Improves code quality
- Makes real warnings visible
- Ensures portability

The gold standard: `-Wall -Wextra -Wpedantic -Werror`
- `-Werror`: Treats all warnings as errors

Additional useful warnings:
- `-Wconversion`: Implicit type conversions
- `-Wshadow`: Variable shadowing
- `-Wformat=2`: Format string vulnerabilities
- `-Wstrict-prototypes`: K&R style function declarations

## What's Broken
The code has multiple warning-producing issues that must be fixed to achieve a zero-warning build.

## Learning Goal
Understand:
- How to build production-quality C code
- Why `-Werror` matters in CI/CD
- Common warning patterns and their fixes

## Fix It
Fix all warnings so the code compiles with `-Wall -Wextra -Wpedantic -Werror`.

## Verify
```bash
gcc -Wall -Wextra -Wpedantic -Werror -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
