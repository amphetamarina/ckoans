# Assigning Sections

## Concept
**Linker scripts** control how sections are arranged in the final executable. You can assign input sections to output sections.

**Basic linker script structure:**
```ld
SECTIONS {
    .text : {
        *(.text)      /* All .text sections */
        *(.text.*)    /* All .text.* sections */
    }
    .data : {
        *(.data)
        *(.data.*)
    }
    .rodata : {
        *(.rodata)
    }
}
```

**Section attributes:**
```c
__attribute__((section(".mydata")))  // Put variable in custom section
```

**Why custom sections:**
- Group related data/code together
- Control placement in memory
- Separate security-critical code
- Optimize cache locality

**Viewing sections:**
```bash
objdump -h binary
readelf -S binary
```

**Using custom linker script:**
```bash
gcc -T linker.ld program.c -o program
```

## What's Broken
The program uses custom sections but the linker script doesn't properly assign them to output sections.

## Learning Goal
- Understand linker script SECTIONS command
- Learn to assign input sections to output sections
- Use section attributes in C code
- Control section placement

## Task
1. Create a linker script that assigns custom sections
2. Compile with: `gcc -T script.ld broken.c -o broken`
3. Verify sections: `readelf -S broken | grep -E 'mysection|mydata'`
4. Fix the section assignments

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
