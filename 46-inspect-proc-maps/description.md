# Inspect /proc/self/maps

## Concept
`/proc/self/maps` shows the memory map of the current process:
- Virtual memory regions (VMAs)
- Address ranges
- Permissions (r=read, w=write, x=execute, p=private, s=shared)
- File mappings (executable, libraries)
- Anonymous mappings (heap, stack)

Format: `address perms offset dev:inode pathname`
Example: `7ffff7dd0000-7ffff7df0000 r-xp 00000000 08:01 123 /lib/libc.so`

## What's Broken
The program doesn't properly display or parse /proc/self/maps information.

## Learning Goal
Understand that:
- `/proc/self/maps` reveals complete memory layout
- Shows stack, heap, code, libraries, etc.
- Permissions indicate segment type (r-x = code, rw- = data)
- Each line represents one memory mapping
- Anonymous regions have no pathname (heap, stack)
- `[heap]`, `[stack]`, `[vdso]` are special markers
- Useful for debugging and understanding memory layout

## Task
1. Compile and run: `gcc -o broken broken.c && ./broken`
2. The program will display its memory map
3. Identify different regions: code, data, heap, stack, libraries
4. Note the permissions and address ranges

## Verify
```bash
gcc -o broken broken.c && ./broken
```
