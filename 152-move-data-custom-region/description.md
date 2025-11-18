# Move .data to Custom Region → Verify

## Concept
Linker scripts can place sections at specific memory addresses, useful for embedded systems with distinct memory regions (Flash, RAM, memory-mapped I/O).

**Memory regions:**
```ld
MEMORY {
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
    SRAM2 (rw)  : ORIGIN = 0x10000000, LENGTH = 16K
}

SECTIONS {
    .text : { *(.text) } > FLASH
    .data : { *(.data) } > RAM AT> FLASH
    .custom : { *(.custom) } > SRAM2
}
```

**AT keyword:**
- Load address (in Flash)
- Runtime address (in RAM)
- Startup code copies from Flash to RAM

**Common use cases:**
- .text in Flash (read-only, persistent)
- .data in RAM (read-write, initialized from Flash)
- .bss in RAM (zero-initialized)
- Memory-mapped peripherals at fixed addresses

**Verification:**
```bash
readelf -S binary  # Section addresses
readelf -l binary  # Segment addresses
objdump -h binary  # Section headers
```

## What's Broken
The program demonstrates placing data in custom memory regions but verification logic is incorrect.

## Learning Goal
- Define memory regions with MEMORY command
- Place sections in specific regions with `> REGION`
- Understand load vs runtime addresses (AT)
- Verify section placement

## Task
1. Create linker script with MEMORY regions
2. Assign sections to regions
3. Verify with: `readelf -S binary | grep -E '(\.data|\.custom)'`
4. Fix verification logic

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
