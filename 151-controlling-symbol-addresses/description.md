# Controlling Symbol Addresses

## Concept
Linker scripts can define symbols and control their addresses, useful for embedded systems and memory-mapped hardware.

**Defining symbols in linker script:**
```ld
SECTIONS {
    .text : {
        _text_start = .;     /* Start of .text */
        *(.text)
        _text_end = .;       /* End of .text */
        _text_size = _text_end - _text_start;
    }
    .data : {
        _data_start = .;
        *(.data)
        _data_end = .;
    }
}
```

**Location counter (.):**
- Current address in output section
- Can be read and assigned
- Advances as data is placed

**Providing symbols:**
```ld
PROVIDE(_heap_start = .);   /* Only if not defined elsewhere */
_stack_top = 0x20000000;     /* Absolute address */
```

**Using in C:**
```c
extern char _text_start[];
extern char _text_end[];
size_t text_size = _text_end - _text_start;
```

## What's Broken
The program tries to use linker-defined symbols but calculates addresses incorrectly.

## Learning Goal
- Define symbols in linker scripts
- Use location counter (.)
- Access linker symbols from C
- Calculate section sizes

## Task
1. Create linker script defining section boundary symbols
2. Use symbols in C: `extern char _symbol[];`
3. Calculate sizes: `_end - _start`
4. Fix address calculations

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
