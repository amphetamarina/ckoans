# Section 7: Systems Integration - Complete Summary

This document summarizes all koans created for Section 7 (Systems Integration).

## Section 7.1: Shared Libraries (Koans 144-148)

### 144-pic-vs-non-pic
**Topic:** Position Independent Code (PIC) vs non-PIC
**Key Concepts:**
- PIC required for shared libraries
- `-fPIC` compiler flag
- GOT/PLT usage in PIC code
- Text relocations in non-PIC code
- ASLR and code sharing benefits

### 145-symbol-visibility
**Topic:** Symbol visibility in shared libraries
**Key Concepts:**
- Visibility attributes: default, hidden, protected, internal
- `__attribute__((visibility("hidden")))`
- `-fvisibility=hidden` compiler flag
- Reducing symbol pollution
- Performance benefits of hidden symbols

### 146-symbol-versioning
**Topic:** Symbol versioning for ABI compatibility
**Key Concepts:**
- GNU symbol versioning
- Version scripts
- `@` and `@@` version notation
- Multiple symbol versions coexisting
- Maintaining backward compatibility

### 147-rpath-vs-runpath
**Topic:** RPATH vs RUNPATH for shared library paths
**Key Concepts:**
- RPATH (searched before LD_LIBRARY_PATH)
- RUNPATH (searched after LD_LIBRARY_PATH)
- `-Wl,-rpath,/path` and `-Wl,--enable-new-dtags`
- Dynamic linker search order
- Security implications

### 148-abi-break-version-script
**Topic:** Fixing ABI breaks with version scripts
**Key Concepts:**
- ABI compatibility issues
- Version scripts for multiple implementations
- `.symver` directives
- Supporting old and new clients
- Graceful API evolution

## Section 7.2: Linker Scripts (Koans 149-152)

### 149-assigning-sections
**Topic:** Assigning input sections to output sections
**Key Concepts:**
- Linker script SECTIONS command
- `__attribute__((section(".name")))`
- Custom section placement
- Section wildcards: `*(.text.*)`
- Controlling section layout

### 150-custom-segment-mapping
**Topic:** Custom segment mapping with PHDRS
**Key Concepts:**
- Sections vs segments
- PHDRS directive
- Segment permissions (R/W/X flags)
- PT_LOAD program headers
- Runtime memory layout

### 151-controlling-symbol-addresses
**Topic:** Controlling symbol addresses in linker scripts
**Key Concepts:**
- Location counter (.)
- Defining symbols: `_symbol = .;`
- PROVIDE directive
- Section boundary markers
- Calculating section sizes

### 152-move-data-custom-region
**Topic:** Moving .data to custom memory regions
**Key Concepts:**
- MEMORY command
- Memory region definitions (FLASH, RAM, etc.)
- Placement with `> REGION`
- AT keyword for load vs runtime addresses
- Embedded systems memory mapping

## Section 7.3: Minimal C Runtime (Koans 153-156)

### 153-start-vs-main
**Topic:** _start vs main entry points
**Key Concepts:**
- _start is the true entry point
- C runtime initialization (crt0)
- Runtime setup before main()
- Global constructors/destructors
- exit() vs _exit()

### 154-argc-argv-env-layout
**Topic:** Stack layout of argc/argv/envp
**Key Concepts:**
- Initial stack layout
- Argument vector parsing
- Environment pointer location
- Pointer arithmetic in _start
- NULL terminators

### 155-syscalls-without-libc
**Topic:** Making syscalls without libc
**Key Concepts:**
- Direct syscall invocation
- x86-64 syscall ABI
- Register mapping (RAX, RDI, RSI, etc.)
- Inline assembly syscalls
- Bypassing libc wrappers

### 156-hello-world-syscalls
**Topic:** Minimal hello-world using only syscalls
**Key Concepts:**
- Writing _start without libc
- SYS_write and SYS_exit syscalls
- `-nostdlib` compilation
- Minimal binary size
- Understanding program requirements

## Section 7.4: Reproducible Builds (Koans 157-160)

### 157-fixed-timestamps
**Topic:** Eliminating timestamp non-determinism
**Key Concepts:**
- Avoiding __DATE__ and __TIME__
- SOURCE_DATE_EPOCH environment variable
- Timestamp sources in builds
- Archive timestamps
- Build integrity verification

### 158-deterministic-archives
**Topic:** Creating deterministic static libraries
**Key Concepts:**
- Archive (.a) file structure
- `ar rcsD` deterministic mode
- Metadata in archives (timestamp, uid, gid)
- `-D` and `-U` flags
- Reproducible static libraries

### 159-stable-ordering
**Topic:** Ensuring stable input ordering
**Key Concepts:**
- Non-deterministic ordering sources
- Filesystem readdir() ordering
- Sorting inputs explicitly
- Build system solutions (Make, CMake)
- Hash table iteration issues

### 160-byte-identical-builds
**Topic:** Achieving byte-identical reproducible builds
**Key Concepts:**
- Complete reproducibility
- All sources of non-determinism
- Compiler flags: `-ffile-prefix-map`, `-frandom-seed`
- Linker flags: `--build-id=none`
- Verification with cryptographic hashes
- diffoscope and reproducibility tools

## Summary Statistics

- **Total Koans:** 17 (koans 144-160)
- **Subsections:** 4
  - 7.1 Shared Libraries: 5 koans
  - 7.2 Linker Scripts: 4 koans
  - 7.3 Minimal C Runtime: 4 koans
  - 7.4 Reproducible Builds: 4 koans

## File Structure

Each koan contains:
- `description.md` - Concept explanation, learning goals, tasks
- `broken.c` - Code with intentional bugs marked as "BUG:"
- `expected.txt` - Expected output when bugs are fixed

## Testing

All koans have been verified to:
1. Compile successfully with gcc
2. Follow the established pattern
3. Include intentional bugs marked with "BUG:"
4. Provide educational value on systems integration topics
