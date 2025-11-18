# Async-Signal-Safe Functions

## Concept
Only **async-signal-safe** functions can be safely called from signal handlers. POSIX defines a specific list of safe functions, including:

**Safe**: write(), read(), _exit(), signal(), raise(), sigaction(), etc.
**Unsafe**: printf(), malloc(), free(), stdio functions, most library functions

Using unsafe functions in handlers causes:
- Data corruption (malloc/free internal state)
- Deadlocks (stdio locks)
- Undefined behavior

To print from a handler, use `write()` with a string literal, not printf().

## What's Broken
The program's signal handler uses async-signal-unsafe functions, causing potential corruption and undefined behavior.

## Learning Goal
- Understand which functions are async-signal-safe
- Learn why unsafe functions cause problems in handlers
- Practice using write() instead of printf() in handlers

## Fix It
Replace unsafe function calls with their async-signal-safe equivalents.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
