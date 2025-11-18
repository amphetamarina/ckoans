# User to Kernel Mode Transition

## Concept
Modern CPUs have **privilege levels** (rings) to protect the kernel from user programs:

**User Mode (Ring 3)**:
- Where normal applications run
- Limited privileges
- Cannot directly access hardware or kernel memory
- Cannot execute privileged instructions

**Kernel Mode (Ring 0)**:
- Where the OS kernel runs
- Full privileges
- Can access all memory and hardware
- Can execute privileged instructions

**System calls** are the mechanism for transitioning from user to kernel mode:

1. **User program** calls a wrapper function (like `write()`)
2. **Wrapper** sets up syscall number and arguments in registers
3. **Trap instruction** (`syscall` on x86-64) switches to kernel mode
4. **CPU** saves user state, switches to kernel stack, jumps to syscall handler
5. **Kernel** validates arguments, performs the operation
6. **Kernel** puts return value in register, executes return instruction
7. **CPU** switches back to user mode
8. **Wrapper** returns to user program

**Why this matters**:
- System calls are relatively expensive (compared to function calls)
- Context switch overhead: save/restore registers, TLB flush
- Security: kernel validates all user input
- Typical cost: 50-200 CPU cycles vs 5-10 for function call

**Tools to observe**:
- `strace` - Traces system calls
- `ltrace` - Traces library calls
- `perf` - Performance analysis showing user/kernel time

## What's Broken
The program makes inefficient syscalls that could be batched or buffered.

## Learning Goal
Understand that:
- User programs cannot directly access kernel resources
- System calls are the only way to request kernel services
- Each syscall has overhead due to mode switching
- Batching operations reduces syscall overhead

## Fix It
Optimize the code to reduce unnecessary system calls by using buffering.

## Verify
```bash
gcc -o broken broken.c && ./broken
# Use strace to see syscalls:
strace -c ./broken 2>&1 | grep write
diff <(./broken) expected.txt
```
