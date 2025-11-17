# C Koans — Systems Programming Through Failure-Driven Learning

This repository is a full, dependency-ordered curriculum for learning C, operating systems, toolchains, and debugging by **fixing broken programs**.  
Every micro-topic below corresponds to **one koan**.

Each koan contains:

```
NN-topic-name/
    description.md
    broken.c
    expected.txt        (optional)
    tests/              (optional)
```

You must proceed strictly in order.

---

# 1. CPU & Memory Grounding

## 1.1 Von Neumann Execution
- 1.1.1 Program counter and sequential execution  
- 1.1.2 Instruction formats (load/store, branch, arithmetic)  
- 1.1.3 Control flow: jumps, calls, returns  
- 1.1.4 Stack vs register machines  
- 1.1.5 Pipeline stalls and hazards  
- 1.1.6 Build minimal 3-instruction loop  
- 1.1.7 Inspect assembly of a 2-line C program (`gcc -S`)

## 1.2 Registers & ABI
- 1.2.1 General-purpose registers  
- 1.2.2 Stack pointer vs frame pointer  
- 1.2.3 Caller-saved vs callee-saved  
- 1.2.4 Argument passing in registers  
- 1.2.5 Return-value register  
- 1.2.6 Prologue/epilogue patterns  
- 1.2.7 Prototype mismatch → dissect crash in `gdb`

## 1.3 Stack Frames
- 1.3.1 Call stack layout  
- 1.3.2 Register spills  
- 1.3.3 Local variable placement  
- 1.3.4 Red zone (System V ABI)  
- 1.3.5 Frame unwinding rules  
- 1.3.6 Inspect stack using `gdb info frame`

## 1.4 Heap Allocation
- 1.4.1 Free-list allocator model  
- 1.4.2 Allocation metadata  
- 1.4.3 Fragmentation  
- 1.4.4 Size classes and alignment  
- 1.4.5 Memory leak → detect with Valgrind  
- 1.4.6 Use-after-free → detect with ASan

---

# 2. Memory Model Literacy

## 2.1 Object Lifetimes
- 2.1.1 Static storage duration  
- 2.1.2 Automatic (stack) storage duration  
- 2.1.3 Dynamic (heap) storage duration  
- 2.1.4 Lifetime vs scope  
- 2.1.5 Returning pointer to dead stack → explain UB

## 2.2 Pointer Arithmetic
- 2.2.1 Pointer as typed offset  
- 2.2.2 Alignment constraints  
- 2.2.3 Strict bounds rules  
- 2.2.4 Integer↔pointer casts  
- 2.2.5 Misaligned struct → detect with UBSan

## 2.3 Aliasing & Effective Type
- 2.3.1 Effective type rules  
- 2.3.2 Strict aliasing violations  
- 2.3.3 Valid aliasing (char*, union, memcpy)  
- 2.3.4 Optimizer assumptions  
- 2.3.5 Miscompile from invalid aliasing at `-O2`

## 2.4 Executable Memory Layout
- 2.4.1 Sections vs segments  
- 2.4.2 .text / .data / .bss  
- 2.4.3 Heap and stack growth  
- 2.4.4 ASLR impact  
- 2.4.5 Inspect `/proc/self/maps`

---

# 3. Compilation Pipeline Fluency

## 3.1 Preprocessor
- 3.1.1 Macro expansion  
- 3.1.2 Include search paths  
- 3.1.3 Conditional compilation  
- 3.1.4 Multiline macro pitfalls  
- 3.1.5 Debug expansion with `gcc -E`  
- 3.1.6 Broken macro → trace expansion

## 3.2 Lexing & Parsing
- 3.2.1 Token categories  
- 3.2.2 Trigraphs, digraphs  
- 3.2.3 Type vs identifier ambiguity  
- 3.2.4 Declarator parsing  
- 3.2.5 Shift/reduce conflicts  
- 3.2.6 Produce parse error → explain grammar

## 3.3 IR & Assembly
- 3.3.1 Compilation phases  
- 3.3.2 LLVM IR structure  
- 3.3.3 SSA form  
- 3.3.4 Machine code emission  
- 3.3.5 Modify IR to flip branch  
- 3.3.6 Identify prologue in GCC assembly

## 3.4 Object Files & Relocations
- 3.4.1 Symbol table  
- 3.4.2 Common relocation types  
- 3.4.3 Section headers  
- 3.4.4 Static vs dynamic relocations  
- 3.4.5 Undefined symbol → inspect `.o` with readelf

## 3.5 Linking
- 3.5.1 Static linking  
- 3.5.2 Dynamic linking  
- 3.5.3 Symbol resolution  
- 3.5.4 PLT/GOT  
- 3.5.5 Versioned symbols  
- 3.5.6 Wrong `-l` → fix linking failure

## 3.6 Executable Formats
- 3.6.1 ELF header  
- 3.6.2 Program headers  
- 3.6.3 ET_EXEC vs ET_DYN  
- 3.6.4 Locate entrypoint in hex dump

---

# 4. OS Interaction Layer

## 4.1 Processes
- 4.1.1 PID, PPID, PGID  
- 4.1.2 `fork` semantics  
- 4.1.3 `exec` overlays  
- 4.1.4 Environment vector  
- 4.1.5 printf before/after fork → explain output ordering

## 4.2 Threads
- 4.2.1 Creating pthreads  
- 4.2.2 Shared memory semantics  
- 4.2.3 Data races  
- 4.2.4 Memory barriers  
- 4.2.5 Race condition → detect with TSAN

## 4.3 Syscalls
- 4.3.1 User→kernel transition  
- 4.3.2 Syscall numbers  
- 4.3.3 errno pathway  
- 4.3.4 Raw syscall via inline asm

## 4.4 File Descriptors
- 4.4.1 Open/close lifecycle  
- 4.4.2 Pipes  
- 4.4.3 Blocking vs nonblocking  
- 4.4.4 Append vs truncate  
- 4.4.5 Rebuild `cat` using only syscalls

## 4.5 Signals
- 4.5.1 Signal dispositions  
- 4.5.2 Reentrancy hazards  
- 4.5.3 SA_RESTART  
- 4.5.4 Async-signal-safe functions  
- 4.5.5 Unsafe handler → repair

---

# 5. Toolchain Mastery

## 5.1 Compiler Flags
- 5.1.1 `-Wall -Wextra -Wpedantic`  
- 5.1.2 Optimization levels  
- 5.1.3 Sanitizers  
- 5.1.4 CPU-target flags  
- 5.1.5 Zero-warning build koan

## 5.2 Build Systems
- 5.2.1 Implicit rules  
- 5.2.2 Dependency inference  
- 5.2.3 Pattern rules  
- 5.2.4 Parallel builds  
- 5.2.5 Break header dependency → diagnose

## 5.3 pkg-config
- 5.3.1 `.pc` file format  
- 5.3.2 Include vs libs flags  
- 5.3.3 Version checks  
- 5.3.4 Wrong package version → detect

---

# 6. Debugging Layer

## 6.1 gdb
- 6.1.1 Breakpoints  
- 6.1.2 Stepping modes  
- 6.1.3 Backtraces  
- 6.1.4 TUI mode  
- 6.1.5 Watchpoints  
- 6.1.6 Stack overflow → catch with watchpoint

## 6.2 Sanitizers
- 6.2.1 Heap OOB  
- 6.2.2 Stack OOB  
- 6.2.3 Use-after-free  
- 6.2.4 Integer overflow  
- 6.2.5 Zero-sanitizer-errors module

## 6.3 Valgrind
- 6.3.1 Memcheck  
- 6.3.2 Callgrind  
- 6.3.3 Cachegrind  
- 6.3.4 Massif  
- 6.3.5 Interpret callgrind diff

## 6.4 strace & ltrace
- 6.4.1 Syscall tracing  
- 6.4.2 Error-path analysis  
- 6.4.3 Blocking detection  
- 6.4.4 Library-call tracing  
- 6.4.5 Hang → trace to wrong file descriptor

## 6.5 Perf
- 6.5.1 Cycle counts  
- 6.5.2 Branch misses  
- 6.5.3 Cache miss patterns  
- 6.5.4 Flamegraphs  
- 6.5.5 Identify branch-miss hotspot

---

# 7. Systems Integration

## 7.1 Shared Libraries
- 7.1.1 PIC vs non-PIC  
- 7.1.2 Symbol visibility  
- 7.1.3 Symbol versioning  
- 7.1.4 RPATH vs RUNPATH  
- 7.1.5 ABI break → fix with version script

## 7.2 Linker Scripts
- 7.2.1 Assigning sections  
- 7.2.2 Custom segment mapping  
- 7.2.3 Controlling symbol addresses  
- 7.2.4 Move `.data` to custom region → verify

## 7.3 Minimal C Runtime
- 7.3.1 `_start` vs `main`  
- 7.3.2 argc/argv/env layout  
- 7.3.3 Syscalls without libc  
- 7.3.4 Write hello-world using only syscalls

## 7.4 Reproducible Builds
- 7.4.1 Fixed timestamps  
- 7.4.2 Deterministic archives  
- 7.4.3 Stable ordering  
- 7.4.4 Produce byte-identical builds

---

Each subtopic is a standalone koan.  
Start at 1.1.1 and progress linearly until the end.

