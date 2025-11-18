# Produce Parse Error - Explain Grammar

## Concept
When the parser encounters syntax that doesn't match C's grammar, it produces a **parse error**. Understanding grammar rules helps diagnose errors.

Common parse errors:
- **Missing semicolons**: Expected `;` before token
- **Unmatched braces**: Expected `}` before token
- **Invalid declarations**: Expected identifier, got keyword
- **Syntax errors**: Unexpected token in expression

C grammar basics:
```
translation-unit → external-declaration+
external-declaration → function-definition | declaration
function-definition → declaration-specifiers declarator compound-statement
declaration → declaration-specifiers init-declarator-list? ;
statement → compound-statement | expression-statement | ...
```

Parsers report errors like:
- "expected ';' before '}' token"
- "expected identifier or '(' before numeric constant"
- "expected declaration specifiers"

## What's Broken
The code has multiple syntax errors that violate C's grammar rules. Compile it to see parse errors, then fix them.

## Learning Goal
Understand:
- How to interpret parse error messages
- What C grammar rules the errors violate
- How to systematically fix parse errors

## Task
1. Try to compile: `gcc broken.c`
2. Read the parse errors carefully
3. Fix each syntax error based on grammar rules
4. Recompile until it works

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
