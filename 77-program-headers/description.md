# Program Headers

## Concept
**Program headers** (also called segments) describe how to load the executable into memory at runtime. They tell the OS/loader:
- What parts of the file to load
- Where to load them in virtual memory
- What permissions to set (read, write, execute)

**Common program header types:**
- **LOAD**: Loadable segment (code or data)
- **DYNAMIC**: Dynamic linking information
- **INTERP**: Path to dynamic linker/interpreter
- **GNU_STACK**: Stack permissions (executable or not)
- **GNU_RELRO**: Read-only after relocation

**Key fields:**
- **Type**: Segment type (LOAD, DYNAMIC, etc.)
- **Offset**: File offset of segment data
- **VirtAddr**: Virtual address to load at
- **PhysAddr**: Physical address (usually same as VirtAddr)
- **FileSiz**: Size in file
- **MemSiz**: Size in memory (can be larger for .bss)
- **Flags**: Permissions (R=read, W=write, E=execute)
- **Align**: Alignment requirement

**Section headers vs Program headers:**
- **Section headers**: For linking, debug info, human-readable
- **Program headers**: For loading/execution, required at runtime

## What's Broken
The program is mostly correct. You'll inspect program headers to see memory layout.

## Learning Goal
- Understand program headers vs section headers
- Learn to inspect with `readelf -l`
- See how code/data segments are loaded
- Understand segment permissions

## Task
1. Compile: `gcc broken.c -o broken`
2. Inspect program headers: `readelf -l broken`
3. Notice LOAD segments with different permissions
4. See INTERP segment (dynamic linker path)
5. Fix program if needed

## Verify
```bash
gcc -o broken broken.c
readelf -l broken | grep -E '(LOAD|INTERP|Type)'
./broken
diff <(./broken) expected.txt
```
