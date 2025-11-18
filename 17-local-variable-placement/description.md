# Local Variable Placement

## Concept
Local variables are placed on the stack at **negative offsets** from the frame pointer (RBP). The compiler decides:
- Offset for each variable based on size and alignment
- Stack layout order (often different from declaration order)
- Whether to keep variables in registers or spill to stack

Arrays and structures always live on the stack because they cannot fit in a single register.

## What's Broken
The program demonstrates stack layout of local variables but has incorrect array indexing.

## Learning Goal
- Understand local variables reside at negative RBP offsets
- See that arrays must be stack-allocated
- Observe compiler's freedom in variable ordering

## Fix It
Fix the array access to correctly compute the sum of array elements.

## Verify
```bash
gcc -O0 -fno-omit-frame-pointer -S broken.c -o broken.s
cat broken.s | grep -A 20 'func:'  # Examine stack offsets
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
