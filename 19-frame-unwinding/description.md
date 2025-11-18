# Frame Unwinding Rules

## Concept
**Frame unwinding** is the process of walking up the call stack from the current frame to parent frames. This is critical for:
- Debugger backtraces (`bt` in gdb)
- Exception handling (C++ exceptions, setjmp/longjmp)
- Profilers and sampling tools

Unwinding uses:
- **Frame pointers (RBP chain)**: Each frame's RBP points to previous frame's RBP
- **DWARF .eh_frame**: Metadata describing how to reconstruct registers at each PC
- Return address is stored at `[RBP + 8]` when using frame pointers

## What's Broken
The program simulates manual stack walking but has incorrect pointer arithmetic for traversing frame pointers.

## Learning Goal
- Understand frame pointer chain links frames together
- See how return addresses are stored on stack
- Recognize unwinding relies on maintaining RBP chain

## Fix It
Fix the frame pointer traversal to correctly walk the stack.

## Verify
```bash
gcc -fno-omit-frame-pointer -O0 -g broken.c -o broken
./broken
diff <(./broken) expected.txt
```
