# Compilation Pipeline Fluency - Sections 3.1-3.3

## Section 3.1: Preprocessor (Koans 47-52)

### 47-macro-expansion
- Concept: Macro textual substitution, operator precedence issues
- Bug: Missing parentheses in macro definitions causing wrong evaluation order
- Files: ✓ description.md, broken.c, expected.txt

### 48-include-search-paths
- Concept: Difference between <> and "" include syntax, search paths
- Bug: Using <> for local header instead of ""
- Files: ✓ description.md, broken.c, expected.txt, myheader.h

### 49-conditional-compilation
- Concept: #ifdef, #ifndef, #if directives for conditional compilation
- Bug: Wrong conditional directives and missing macro definitions
- Files: ✓ description.md, broken.c, expected.txt

### 50-multiline-macro-pitfalls
- Concept: do-while(0) wrapper, double evaluation, multiline syntax
- Bug: Missing do-while wrapper, double evaluation in macros
- Files: ✓ description.md, broken.c, expected.txt

### 51-debug-expansion-gcc-e
- Concept: Using gcc -E to debug macro expansions
- Bug: Wrong macro formulas and missing parentheses
- Files: ✓ description.md, broken.c, expected.txt

### 52-broken-macro-trace
- Concept: Systematic debugging of macro bugs through expansion tracing
- Bug: Multiple macro issues with precedence and parenthesization
- Files: ✓ description.md, broken.c, expected.txt

## Section 3.2: Lexing & Parsing (Koans 53-58)

### 53-token-categories
- Concept: Six token categories, valid identifier rules, literal syntax
- Bug: Invalid identifiers, malformed literals, syntax errors
- Files: ✓ description.md, broken.c, expected.txt

### 54-trigraphs-digraphs
- Concept: Historical character alternatives (??=, <:, etc.)
- Bug: Using digraphs and accidental trigraph sequences
- Files: ✓ description.md, broken.c, expected.txt

### 55-type-identifier-ambiguity
- Concept: Parser ambiguity between types and identifiers (T * x)
- Bug: Missing typedef declarations causing ambiguity
- Files: ✓ description.md, broken.c, expected.txt

### 56-declarator-parsing
- Concept: Complex declarator syntax (arrays, pointers, functions)
- Bug: Wrong declarator syntax confusing array/pointer relationships
- Files: ✓ description.md, broken.c, expected.txt

### 57-shift-reduce-conflicts
- Concept: Parser conflicts, dangling-else problem
- Bug: Ambiguous if-else nesting requiring braces
- Files: ✓ description.md, broken.c, expected.txt

### 58-parse-error-grammar
- Concept: Understanding parse errors and C grammar rules
- Bug: Multiple syntax errors (missing semicolons, braces, etc.)
- Files: ✓ description.md, broken.c, expected.txt

## Section 3.3: IR & Assembly (Koans 59-64)

### 59-compilation-phases
- Concept: Four compilation phases (preprocess, compile, assemble, link)
- Bug: Issues caught at different compilation stages
- Files: ✓ description.md, broken.c, expected.txt

### 60-llvm-ir-structure
- Concept: LLVM IR structure (modules, functions, basic blocks)
- Bug: Incorrect computations visible in IR structure
- Files: ✓ description.md, broken.c, expected.txt

### 61-ssa-form
- Concept: Static Single Assignment form, phi functions
- Bug: Redundant assignments creating extra SSA versions
- Files: ✓ description.md, broken.c, expected.txt

### 62-machine-code-emission
- Concept: Assembly to machine code, using objdump
- Bug: Inefficient code patterns in generated machine code
- Files: ✓ description.md, broken.c, expected.txt

### 63-modify-ir-flip-branch
- Concept: Manually editing LLVM IR, branch instructions
- Bug: Inverted branch conditions requiring IR manipulation
- Files: ✓ description.md, broken.c, expected.txt

### 64-identify-prologue-gcc
- Concept: Function prologue/epilogue in assembly
- Bug: Exercise to identify prologue in generated assembly
- Files: ✓ description.md, broken.c, expected.txt

## Summary Statistics
- Total koans created: 18 (47-64)
- Total files created: 55
- All koans follow TDD pattern with "BUG:" markers
- All koans include description.md, broken.c, and expected.txt
