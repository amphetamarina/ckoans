# Integer ↔ Pointer Casts

## Concept
Casting between pointers and integers:
- `uintptr_t` is guaranteed to hold any pointer value
- `intptr_t` is the signed equivalent
- Casting pointer → integer → pointer can lose information on some systems
- Pointer provenance rules mean you can't create arbitrary valid pointers
- This is implementation-defined, not portable

Common uses:
- Low-level debugging (print pointer as integer)
- Hardware interfacing (memory-mapped I/O)
- Alignment checking (`addr % alignment == 0`)

## What's Broken
The program incorrectly casts between pointers and integers, potentially losing information or creating invalid pointers.

## Learning Goal
Understand that:
- `uintptr_t` is the safe way to hold pointer values as integers
- Not all integers can become valid pointers (provenance)
- Round-trip pointer → integer → pointer is implementation-defined
- Use `%p` for printing pointers, not manual casting
- Be aware of pointer size (32-bit vs 64-bit)

## Fix It
Use `uintptr_t` for safe pointer-to-integer conversions.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
