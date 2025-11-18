# Machine Code Emission

## Concept
The final compilation stage converts assembly (or IR) to **machine code** - binary instructions the CPU executes.

Stages:
1. **IR → Assembly**: Backend code generation
   - `clang -S` or `gcc -S` produces `.s` file
2. **Assembly → Object code**: Assembler
   - `as file.s -o file.o` or `gcc -c`
   - Produces relocatable object file
3. **Object code inspection**:
   - `objdump -d file.o`: Disassemble
   - `readelf -h file.o`: ELF header
   - `nm file.o`: Symbol table

Machine code properties:
- **Binary format**: Hex bytes representing instructions
- **Relocatable**: Addresses not yet finalized (linker fills them)
- **Architecture-specific**: x86-64, ARM, etc.

Example disassembly:
```
0000000000001129 <add>:
    1129:  55                push   %rbp
    112a:  48 89 e5          mov    %rsp,%rbp
    112d:  89 7d fc          mov    %edi,-0x4(%rbp)
```

## What's Broken
The code will compile to machine code with inefficiencies. Use objdump to examine the generated assembly and machine code.

## Learning Goal
Understand:
- How source code becomes machine code
- Using `objdump -d` to disassemble object files
- Reading machine code hex bytes
- Relationship between assembly mnemonics and machine code

## Task
1. Compile to object: `gcc -c broken.c -o broken.o`
2. Disassemble: `objdump -d broken.o`
3. Examine machine code and assembly
4. Compile to executable and run

## Verify
```bash
gcc -c broken.c -o broken.o
objdump -d broken.o | grep -A 5 "<main>:"
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
