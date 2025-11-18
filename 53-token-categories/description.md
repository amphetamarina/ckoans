# Token Categories

## Concept
The lexer (lexical analyzer) breaks source code into **tokens** - the smallest meaningful units. C has six token categories:

1. **Keywords**: Reserved words (`int`, `if`, `return`, `while`, etc.)
2. **Identifiers**: Variable/function names (`foo`, `count`, `my_var`)
3. **Constants**: Literal values (`42`, `3.14`, `'a'`, `"hello"`)
4. **String literals**: `"hello world"`
5. **Operators**: `+`, `-`, `*`, `/`, `==`, `&&`, etc.
6. **Punctuators**: `;`, `{`, `}`, `(`, `)`, `,`, etc.

Whitespace and comments are discarded (not tokens).

The lexer:
- Recognizes token boundaries (longest match rule)
- Classifies each token
- Passes tokens to the parser

## What's Broken
The code has lexical issues: invalid identifiers, wrong literal syntax, or missing delimiters.

## Learning Goal
Understand:
- How source code is tokenized
- Valid identifier rules (start with letter/underscore, contain alphanumeric/underscore)
- Literal constant syntax
- Operator and punctuator tokens

## Fix It
Correct the lexical errors so the code tokenizes properly.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
