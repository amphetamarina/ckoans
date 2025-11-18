# Signal Dispositions

## Concept
Every signal has a **disposition** that determines what happens when it's delivered. The three dispositions are:

1. **Default (SIG_DFL)** - Kernel's default action (usually terminate, ignore, stop, or continue)
2. **Ignore (SIG_IGN)** - Signal is discarded; no action taken
3. **Handler** - Custom function executes in response to the signal

Use `sigaction()` to set a signal's disposition. Unlike the obsolete `signal()`, sigaction provides reliable, portable behavior.

## What's Broken
The program attempts to handle SIGINT (Ctrl-C) but uses incorrect signal handling setup, causing it to fail to catch the signal properly.

## Learning Goal
- Understand signal dispositions (default, ignore, handler)
- Learn to use sigaction() properly
- See the difference between SIG_DFL, SIG_IGN, and custom handlers

## Fix It
Fix the sigaction setup to properly install the signal handler.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
