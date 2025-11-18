# LLVM IR Structure

## Concept
**LLVM IR** (Intermediate Representation) is a low-level, typed, assembly-like language used by modern compilers (Clang, Rust, Swift).

Key components:

1. **Modules**: Top-level container (one per source file)
2. **Functions**: `define i32 @main() { ... }`
3. **Basic blocks**: Labeled sequences of instructions ending in terminator
4. **Instructions**: Operations like `add`, `load`, `store`, `call`
5. **Types**: `i32` (32-bit int), `i8*` (char pointer), etc.

Example IR:
```llvm
define i32 @add(i32 %a, i32 %b) {
entry:
  %sum = add i32 %a, %b
  ret i32 %sum
}
```

Generate LLVM IR with Clang:
```bash
clang -S -emit-llvm source.c -o source.ll
```

## What's Broken
The C code will compile to LLVM IR with incorrect structure. Generate the IR and examine it to understand what needs fixing.

## Learning Goal
Understand:
- LLVM IR basic structure
- How to generate IR with `clang -S -emit-llvm`
- Reading and interpreting IR code
- Relationship between C code and IR

## Task
1. Generate IR: `clang -S -emit-llvm broken.c -o broken.ll`
2. Examine the IR file to see the structure
3. Fix the C code so IR produces correct results
4. Compare corrected IR

## Verify
```bash
clang -S -emit-llvm broken.c -o broken.ll
clang -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
