# Implicit Rules

## Concept
Make has built-in **implicit rules** for common tasks:
- `%.o: %.c` - Compile C source to object file
- `%: %.c` - Compile and link C program
- `%: %.o` - Link object file to executable

Implicit rules use automatic variables:
- `$@` - Target name
- `$<` - First prerequisite
- `$^` - All prerequisites
- `$?` - Prerequisites newer than target

Key variables that control implicit rules:
- `CC` - C compiler (default: `cc`)
- `CFLAGS` - Compiler flags
- `LDFLAGS` - Linker flags
- `LDLIBS` - Libraries to link

## What's Broken
The Makefile tries to override or misuse implicit rules, causing build failures.

## Learning Goal
Understand:
- How Make's implicit rules work
- How to use CFLAGS, LDFLAGS, and LDLIBS properly
- When to use implicit vs explicit rules

## Fix It
Fix the Makefile to properly use or override implicit rules.

## Verify
```bash
make
./program
diff <(./program) expected.txt
make clean
```
