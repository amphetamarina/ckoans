# Effective Type Rules

## Concept
In C, every object has an **effective type**:
- For declared variables, it's the declared type
- For allocated memory (malloc), it's determined by the first write
- The effective type controls what pointer types can access it

**Strict aliasing rule**: An object can only be accessed through:
1. A pointer to its effective type
2. A qualified version (const, volatile)
3. A signed/unsigned variant
4. A character type (char, unsigned char, signed char)
5. An aggregate type containing one of the above

## What's Broken
The program doesn't properly respect effective types when accessing memory.

## Learning Goal
Understand that:
- Every object has an effective type
- The effective type is established at creation or first write
- Accessing through incompatible pointer types is undefined behavior
- The compiler optimizes based on these rules
- Character types can alias anything (byte-wise access)

## Fix It
Use proper types or character arrays for generic byte access.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
