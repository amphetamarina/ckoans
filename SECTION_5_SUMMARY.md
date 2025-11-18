# Section 5: Toolchain Mastery - Koans Summary

All 14 koans for Section 5 have been generated successfully.

## 5.1 Compiler Flags (Koans 104-108)

### 104-wall-wextra-wpedantic
**Concept**: Understanding GCC warning flags (-Wall, -Wextra, -Wpedantic)
**Bug Types**:
- Missing return types
- Unused variables
- Implicit conversions
- Extra semicolons
- Signed/unsigned comparisons
- Missing return statements

### 105-optimization-levels
**Concept**: How optimization levels (-O0, -O1, -O2, -O3) affect code behavior
**Bug Types**:
- Undefined behavior in increment operations (x++ + x++)
- Signed integer overflow
- Uninitialized variables
- Code that works at -O0 but fails at -O2

### 106-sanitizers
**Concept**: Using AddressSanitizer and UndefinedBehaviorSanitizer
**Bug Types**:
- Buffer overflow
- Use-after-free
- Signed integer overflow (UB)
- Null pointer dereference

### 107-cpu-target-flags
**Concept**: CPU-specific compilation flags (-march, -mtune, feature flags)
**Bug Types**:
- Assumes SSE2/AVX availability without checking
- Architecture-specific inline assembly
- Pointer size assumptions

### 108-zero-warning-build
**Concept**: Building with -Wall -Wextra -Wpedantic -Werror
**Bug Types**:
- K&R style function declarations
- Unused functions and parameters
- Variable shadowing
- Implicit type conversions
- Format string issues
- Missing const qualifiers

## 5.2 Build Systems (Koans 109-113)

### 109-implicit-rules
**Concept**: Make's built-in implicit rules and standard variables
**Bug Types**:
- Wrong variable names (COMPILER instead of CC)
- Incorrect automatic variable usage ($< vs $@)
- Missing .PHONY declarations
- Fighting against implicit rules

### 110-dependency-inference
**Concept**: Auto-generating header dependencies with -MMD -MP
**Bug Types**:
- Missing dependency tracking
- Headers not listed as prerequisites
- No .d file inclusion
- Incomplete clean target (doesn't remove .d files)

### 111-pattern-rules
**Concept**: Writing pattern rules with % and automatic variables
**Bug Types**:
- Wrong automatic variables ($@ instead of $<)
- Incorrect stem matching
- Pattern conflicts
- Using $* incorrectly

### 112-parallel-builds
**Concept**: Making builds work correctly with make -j
**Bug Types**:
- Missing directory dependencies
- Race conditions in directory creation
- Missing dependencies on generated headers
- Objects built before prerequisites exist

### 113-break-header-dependency
**Concept**: Diagnosing missing header dependencies
**Bug Types**:
- Missing -MMD -MP flags
- No .d file inclusion
- Changes to headers don't trigger rebuilds
- Incomplete clean target

## 5.3 pkg-config (Koans 114-117)

### 114-pc-file-format
**Concept**: Structure and syntax of .pc files
**Bug Types**:
- Missing prefix variable
- Wrong variable references
- Missing required fields (Description)
- Incorrect flag format (-I missing)
- Wrong flag order (-l before -L)
- Typos in field names (Require vs Requires)

### 115-include-vs-libs-flags
**Concept**: Proper use of --cflags vs --libs
**Bug Types**:
- Using --libs for compilation
- Using --cflags for linking
- Confusing when each flag type is needed
- Wrong flag placement in Makefile

### 116-version-checks
**Concept**: Checking library versions with pkg-config
**Bug Types**:
- Wrong comparison operator (> instead of >=)
- Using --modversion for version comparison
- Checking exact match instead of minimum version
- Querying flags without checking existence first

### 117-wrong-package-version
**Concept**: Diagnosing version mismatches
**Bug Types**:
- Makefile requires version 3.0
- Installed package is only version 2.5
- Students must diagnose and fix the mismatch
- Includes version-info target for debugging

## File Structure

Each koan contains:
- `description.md` - Concept explanation, learning goals, verification steps
- `broken.c` or `Makefile` - Code with intentional bugs marked as "BUG:"
- `expected.txt` - Expected output after fixing
- Supporting files (headers, .pc files, etc.) as needed

## Key Learning Objectives

1. **Compiler Flags**: Understanding warning levels, optimizations, sanitizers, and CPU targeting
2. **Build Systems**: Mastering Make's implicit rules, dependencies, patterns, and parallel builds
3. **pkg-config**: Managing library dependencies, version checks, and proper flag usage

All koans follow the TDD (Test-Driven Development) pattern where students:
1. Read the broken code
2. Understand the concept
3. Fix the bugs
4. Verify against expected output
