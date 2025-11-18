# argc/argv/env Layout

## Concept
When a program starts, the kernel places **argc**, **argv**, and **envp** on the stack in a specific layout that _start must parse.

**Stack layout at program start (x86-64):**
```
High addresses
+------------------+
| envp[n] = NULL   |
| envp[n-1]        |
| ...              |
| envp[0]          |  Environment pointers
+------------------+
| argv[argc] = NULL|
| argv[argc-1]     |
| ...              |
| argv[1]          |
| argv[0]          |  Argument pointers
+------------------+
| argc             |  Argument count
+------------------+ <- RSP at _start
Low addresses
```

**Each pointer points to:**
- Null-terminated strings further up the stack
- Format: `"key=value"` for environment
- Format: `"argument"` for argv

**Accessing from _start:**
```c
void _start(void) {
    long *stack = ...; // RSP value
    long argc = *stack;
    char **argv = (char **)(stack + 1);
    char **envp = argv + argc + 1;
}
```

**The third main parameter:**
```c
int main(int argc, char *argv[], char *envp[])
```

## What's Broken
The program demonstrates stack layout parsing but has incorrect pointer arithmetic.

## Learning Goal
- Understand initial stack layout
- Learn how argc/argv/envp are organized
- Parse stack manually like _start does
- See the contiguous memory layout

## Task
1. Print stack layout at program start
2. Parse argc from stack
3. Follow argv and envp pointers
4. Fix pointer arithmetic

## Verify
```bash
gcc -o broken broken.c
./broken arg1 arg2
diff <(./broken arg1 arg2) expected.txt
```
