# RPATH vs RUNPATH

## Concept
**RPATH** and **RUNPATH** are embedded paths in ELF binaries that tell the dynamic linker where to find shared libraries.

**RPATH (older):**
- Embedded at link time with `-Wl,-rpath,/path`
- Searched BEFORE `LD_LIBRARY_PATH`
- Cannot be overridden by environment
- Security risk (hard to override)

**RUNPATH (newer):**
- Embedded with `-Wl,--enable-new-dtags,-rpath,/path`
- Searched AFTER `LD_LIBRARY_PATH`
- Can be overridden by environment
- More flexible, preferred

**Search order with RPATH:**
1. RPATH
2. LD_LIBRARY_PATH (ignored if RPATH set!)
3. RUNPATH
4. /etc/ld.so.cache
5. Default paths (/lib, /usr/lib)

**Search order with RUNPATH:**
1. RPATH (if no RUNPATH)
2. LD_LIBRARY_PATH
3. RUNPATH
4. /etc/ld.so.cache
5. Default paths

**Inspecting:**
```bash
readelf -d binary | grep -E 'RPATH|RUNPATH'
patchelf --print-rpath binary
```

## What's Broken
The program demonstrates RPATH/RUNPATH but has incorrect path configurations.

## Learning Goal
- Understand RPATH vs RUNPATH differences
- Learn dynamic linker search order
- See security implications
- Use readelf to inspect runtime paths

## Task
1. Compile with RPATH: `gcc -Wl,-rpath,/custom/path broken.c -o broken`
2. Compile with RUNPATH: `gcc -Wl,--enable-new-dtags,-rpath,/custom/path broken.c`
3. Check: `readelf -d broken | grep -E 'RPATH|RUNPATH'`
4. Fix the path logic

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
