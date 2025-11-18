# TUI Mode - Visual Source-Level Debugging

## Concept
**TUI (Text User Interface) mode** provides a split-screen view in gdb showing:

- Source code window
- Command window
- Assembly window (optional)
- Register window (optional)

TUI commands:
- **tui enable** or **Ctrl-X A**: Toggle TUI mode
- **layout src**: Show source code
- **layout asm**: Show assembly
- **layout split**: Show both source and assembly
- **layout regs**: Add register window
- **focus cmd/src**: Switch focus between windows
- **refresh**: Redraw the screen

TUI mode helps visualize code flow during debugging.

## What's Broken
The program has an off-by-one error. Use TUI mode to watch the source as you step through.

## Learning Goal
- Enable and navigate TUI mode
- Watch source code execution in real-time
- Switch between different layouts
- Use TUI to track loop iterations

## Task
1. Compile with debug info: `gcc -g broken.c -o broken`
2. Run in gdb with TUI: `gdb -tui ./broken`
3. Set breakpoint and step through: `break main`, `run`, `next`
4. Watch the source window highlight each line
5. Find and fix the off-by-one error

## Verify
```bash
gcc -g broken.c -o broken
# Example gdb TUI session:
# (gdb) tui enable
# (gdb) layout src
# (gdb) break main
# (gdb) run
# (gdb) next  (watch source window update)
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
