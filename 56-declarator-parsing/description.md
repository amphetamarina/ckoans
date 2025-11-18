# Declarator Parsing

## Concept
C declarator syntax is notoriously complex. Reading "inside-out, right-to-left":

```c
int *p;              // p is a pointer to int
int *p[10];          // p is an array of 10 pointers to int
int (*p)[10];        // p is a pointer to an array of 10 ints
int *f();            // f is a function returning pointer to int
int (*f)();          // f is a pointer to function returning int
int (*(*fp)())[10];  // fp is a pointer to function returning
                     //    pointer to array of 10 ints
```

Operator precedence in declarators:
1. Parentheses `()`, brackets `[]` (left-to-right)
2. Prefix `*` (right-to-left)

The **right-left rule**:
1. Start with identifier
2. Go right when possible (arrays, functions)
3. Go left when blocked (pointers)
4. Jump out of parentheses

## What's Broken
The declarations are incorrect - arrays, pointers, and functions are mixed up.

## Learning Goal
Understand:
- How to read complex C declarators
- Difference between array of pointers vs pointer to array
- Function pointers vs functions returning pointers

## Fix It
Correct the declarator syntax using parentheses appropriately.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
