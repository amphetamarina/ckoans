# Custom Segment Mapping

## Concept
**Segments** (program headers) define memory regions at runtime. Linker scripts can create custom segments with specific permissions and alignment.

**Sections vs Segments:**
- Sections: Link-time view (smaller units)
- Segments: Runtime view (loadable regions)
- Multiple sections can map to one segment

**Creating segments in linker script:**
```ld
PHDRS {
    text PT_LOAD FLAGS(5);    /* R+X */
    data PT_LOAD FLAGS(6);    /* RW */
    custom PT_LOAD FLAGS(7);  /* RWX (avoid in practice!) */
}

SECTIONS {
    .text : { *(.text) } :text
    .data : { *(.data) } :data
    .custom : { *(.custom) } :custom
}
```

**Segment flags:**
- 4 = Read (R)
- 2 = Write (W)
- 1 = Execute (X)
- Combine: 5=R+X, 6=R+W, 7=R+W+X

**Viewing segments:**
```bash
readelf -l binary
objdump -p binary
```

## What's Broken
The program creates custom sections but doesn't map them to appropriate segments.

## Learning Goal
- Understand segment creation with PHDRS
- Learn segment permissions and flags
- Map sections to specific segments
- See runtime memory layout

## Task
1. Create linker script with PHDRS directive
2. Map custom sections to segments with appropriate permissions
3. Compile: `gcc -T script.ld broken.c -o broken -Wl,-z,execstack`
4. Check segments: `readelf -l broken`

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
