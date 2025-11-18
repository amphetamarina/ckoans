# Valid Aliasing (char*, union, memcpy)

## Concept
While most type punning violates strict aliasing, these approaches are **valid**:

1. **Character types**: `char*`, `unsigned char*`, `signed char*` can alias anything
   - Used for byte-wise access, serialization
2. **Unions**: Reading different union members is implementation-defined (but widely supported)
   - Common idiom for type punning
3. **memcpy**: Copies bytes without aliasing
   - Compiler can optimize away the copy

These are the safe, portable ways to reinterpret data.

## What's Broken
The program uses invalid type punning instead of the safe methods.

## Learning Goal
Understand that:
- Character pointers can access any object's bytes
- Unions provide safe type punning (though technically implementation-defined)
- `memcpy` is the most portable way to reinterpret bits
- Modern compilers optimize memcpy away (no performance cost)
- These methods don't violate strict aliasing

## Fix It
Replace pointer casts with unions or memcpy for type punning.

## Verify
```bash
gcc -O2 -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
