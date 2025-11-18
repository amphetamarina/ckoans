# .pc File Format

## Concept
**pkg-config** uses `.pc` files to provide compile and link flags for libraries.

A `.pc` file structure:
```
prefix=/usr/local
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include

Name: MyLibrary
Description: My example library
Version: 1.0.0
Cflags: -I${includedir}
Libs: -L${libdir} -lmylib
Requires: dependency1 >= 2.0
```

Key fields:
- **Variables**: `prefix`, `libdir`, `includedir` (for path abstraction)
- **Name**: Package name
- **Description**: Human-readable description
- **Version**: Package version
- **Cflags**: Compiler flags (usually `-I` for headers)
- **Libs**: Linker flags (`-L` for library path, `-l` for library name)
- **Requires**: Dependencies on other packages

## What's Broken
The `.pc` file has syntax errors and missing fields that prevent pkg-config from working.

## Learning Goal
Understand:
- The structure of `.pc` files
- How variable substitution works
- Required vs optional fields
- How to test `.pc` files

## Fix It
Fix the `.pc` file so pkg-config can read it and provide the correct flags.

## Verify
```bash
export PKG_CONFIG_PATH=.
pkg-config --cflags mylib
pkg-config --libs mylib
gcc $(pkg-config --cflags mylib) -o program program.c $(pkg-config --libs mylib)
./program
diff <(./program) expected.txt
```
