# _start vs main

## Concept
The **_start** symbol is the true entry point of a program, not `main()`. The C runtime (crt0) sets up the environment before calling `main()`.

**Execution flow:**
1. Kernel loads program, jumps to `_start`
2. `_start` (in crt0.o) sets up runtime environment
3. Calls `__libc_start_main`
4. `__libc_start_main` calls your `main()`
5. `main()` returns to runtime
6. Runtime calls `exit()` with return value

**What crt0/_start does:**
- Sets up stack
- Initializes .bss (zero-initialize)
- Copies .data from binary to RAM
- Sets up argc/argv/envp
- Calls global constructors
- Calls `main()`
- Calls `exit()` with return value

**Bypassing the runtime:**
```c
void _start(void) {
    // Your code here
    _exit(0);  // Must exit manually
}
// Compile: gcc -nostdlib -static program.c
```

**Finding entry point:**
```bash
readelf -h binary | grep Entry
objdump -f binary
```

## What's Broken
The program demonstrates the difference between _start and main but has incorrect flow.

## Learning Goal
- Understand _start is the real entry point
- Learn what C runtime initialization does
- See the role of crt0.o
- Write code without standard library

## Task
1. Examine entry point: `readelf -h /bin/ls | grep Entry`
2. Find _start: `objdump -d /bin/ls | grep '<_start>'`
3. Understand initialization sequence
4. Fix the execution flow

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
