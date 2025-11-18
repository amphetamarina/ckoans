# Unsafe Signal Handler Repair

## Concept
This koan brings together all signal handling concepts to fix a badly broken handler. Common mistakes include:

1. **Using unsafe functions** (printf, malloc, stdio)
2. **Not initializing sigaction properly** (garbage in sa_mask, sa_flags)
3. **Incorrect flag usage** (missing SA_RESTART when needed)
4. **Reentrancy violations** (modifying complex data structures)

The **correct pattern**:
```c
struct sigaction sa;
memset(&sa, 0, sizeof(sa));
sa.sa_handler = handler_func;
sigemptyset(&sa.sa_mask);
sa.sa_flags = SA_RESTART;  // if desired
sigaction(SIGNUM, &sa, NULL);
```

In the handler: only use async-signal-safe functions and sig_atomic_t variables.

## What's Broken
The signal handler violates multiple safety rules. Fix all the issues to make it safe.

## Learning Goal
- Apply all signal handling best practices
- Identify and fix multiple handler safety violations
- Build correct, robust signal handlers

## Fix It
Fix the sigaction setup and replace unsafe operations in the handler.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
