# Type vs Identifier Ambiguity

## Concept
C's parser faces **type vs identifier ambiguity**: when seeing a name, is it a type or a variable?

Examples:
```c
typedef int MyInt;
MyInt x;        // MyInt is a type
MyInt * x;      // Multiplication or pointer declaration?
```

This creates the **typedef ambiguity problem**:
```c
T * x;  // Is T a type (pointer declaration) or variable (multiplication)?
```

The parser needs a **symbol table** during parsing to track which identifiers are typedefs. This makes C's grammar **context-sensitive** (not strictly context-free).

Common confusing cases:
- Cast vs multiplication: `(type)*p` vs `(a)*p`
- Function pointer declarations
- `sizeof` expressions

## What's Broken
The code has ambiguous declarations or missing typedef declarations that confuse the meaning.

## Learning Goal
Understand:
- Type vs identifier ambiguity in C
- Why C parser needs symbol table during parsing
- How typedefs affect parsing

## Fix It
Add missing typedef declarations or clarify ambiguous syntax.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
