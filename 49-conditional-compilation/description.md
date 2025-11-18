# Conditional Compilation

## Concept
The preprocessor supports conditional compilation using directives:
- `#ifdef`, `#ifndef`: Check if macro is defined
- `#if defined(X)`: More flexible condition checking
- `#elif`, `#else`, `#endif`: Control flow
- `#if`, `#elif` with expressions: `#if VERSION >= 2`

Common use cases:
- Platform-specific code (`#ifdef _WIN32`)
- Debug vs release builds (`#ifdef DEBUG`)
- Feature flags (`#ifdef FEATURE_ENABLED`)

Macros can be defined via:
- `#define` in source code
- `-D` compiler flag: `gcc -DDEBUG=1`

## What's Broken
The conditional compilation directives are incorrect, causing wrong code sections to compile.

## Learning Goal
Understand:
- How `#ifdef`, `#ifndef`, `#if` work
- Difference between defined/undefined macros
- Using `-D` flag to define macros at compile time

## Fix It
Correct the conditional directives and define/undefine macros appropriately.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
gcc -DDEBUG -o broken broken.c && ./broken  # Try with DEBUG defined
```
