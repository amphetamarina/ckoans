# Static Storage Duration

## Concept
Objects with **static storage duration** exist for the entire lifetime of the program. They are:
- Allocated before `main()` begins
- Initialized once (zero-initialized by default)
- Destroyed after `main()` returns
- Include global variables, `static` local variables, and `static` globals

## What's Broken
The program tries to use a counter but the variable loses its value between function calls instead of persisting.

## Learning Goal
Understand that:
- Static variables retain their values across function calls
- They are initialized only once, not on each function call
- Static storage duration means lifetime = program lifetime
- Local static variables have function scope but static lifetime

## Fix It
Add the `static` keyword to make the counter persist across function calls.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
