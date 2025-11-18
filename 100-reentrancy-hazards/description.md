# Reentrancy Hazards in Signal Handlers

## Concept
A **reentrant** function can be safely interrupted and called again before the previous invocation completes. Signal handlers create reentrancy hazards because they can interrupt code at any point.

**Non-reentrant hazards**:
- Static/global variables without protection
- malloc/free (internal state corruption)
- Standard I/O functions (buffering state)
- Any function that uses static storage

The main program might be in the middle of malloc() when a signal arrives. If the handler calls malloc(), internal heap structures become corrupted.

## What's Broken
The program's signal handler uses non-reentrant functions, causing undefined behavior and data corruption.

## Learning Goal
- Understand what makes a function non-reentrant
- See how signal handlers can corrupt program state
- Learn why only async-signal-safe functions are allowed in handlers

## Fix It
Replace non-reentrant function calls with async-signal-safe alternatives.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
