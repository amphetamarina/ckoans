# Pointer as Typed Offset

## Concept
Pointer arithmetic is **typed** - when you do `ptr + 1`, it advances by `sizeof(*ptr)` bytes, not 1 byte:
- `int* p; p + 1` advances by 4 bytes (on most systems)
- `char* p; p + 1` advances by 1 byte
- `double* p; p + 1` advances by 8 bytes (on most systems)

The compiler knows the type and scales the offset automatically.

## What's Broken
The program incorrectly treats pointer arithmetic as byte offsets instead of element offsets.

## Learning Goal
Understand that:
- `ptr + n` means "n elements forward", not "n bytes forward"
- The compiler multiplies `n` by `sizeof(*ptr)` automatically
- This is why pointer arithmetic requires typed pointers
- `void*` arithmetic is not standard (GCC allows it as extension)
- Array indexing `arr[i]` is equivalent to `*(arr + i)`

## Fix It
Correct the pointer arithmetic to use element offsets instead of trying to manually calculate byte offsets.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
