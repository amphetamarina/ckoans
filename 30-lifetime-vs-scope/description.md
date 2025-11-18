# Lifetime vs Scope

## Concept
**Scope** and **lifetime** are different concepts:
- **Scope**: Where in the code a name is visible (compile-time concept)
- **Lifetime**: When in program execution an object exists (runtime concept)

A variable can have:
- Limited scope (only visible in one function)
- Extended lifetime (exists throughout program execution)

Example: `static` local variables have function scope but static lifetime.

## What's Broken
The program confuses scope with lifetime, trying to access variables outside their scope even though they still exist in memory.

## Learning Goal
Understand that:
- Scope determines where you can *name* a variable
- Lifetime determines when memory is *valid*
- Static local variables: function scope, program lifetime
- Automatic variables: block scope, block lifetime
- You can have narrow scope but long lifetime (static local)

## Fix It
Use static local variables to maintain state while keeping scope limited.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
