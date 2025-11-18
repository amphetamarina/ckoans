# Append vs Truncate File Modes

## Concept
When opening a file for writing with `open()`, different flags control how existing content is handled:

- **O_TRUNC** - Truncate file to zero length if it exists (discard existing content)
- **O_APPEND** - All writes go to the end of file (atomic append)
- **Neither** - File offset starts at beginning; writes can overwrite existing content

**O_APPEND** is crucial for log files: it guarantees atomic append even when multiple processes write to the same file simultaneously.

## What's Broken
The program is supposed to append log entries to a file, but uses the wrong flags, causing data loss.

## Learning Goal
- Understand the difference between O_TRUNC and O_APPEND
- Learn when to use each mode
- See how O_APPEND prevents data loss in concurrent writes

## Fix It
Use the correct flags when opening the log file to append rather than truncate.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
