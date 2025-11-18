# Shift/Reduce Conflicts

## Concept
Parser generators (like YACC/Bison) use **shift-reduce parsing**. A conflict occurs when the parser can't decide whether to:
- **Shift**: Read next token
- **Reduce**: Apply a grammar rule

**Shift/reduce conflict** example - the "dangling else":
```c
if (a) if (b) x = 1; else x = 2;
```
When parser sees `else`, should it:
- Shift (read `else`, associating it with inner `if`)
- Reduce (complete inner `if`, associating `else` with outer `if`)

C resolves this by **shift precedence**: `else` associates with nearest `if`.

**Reduce/reduce conflict**: Multiple grammar rules could apply. Usually indicates ambiguous grammar.

## What's Broken
The code has ambiguous if-else nesting that demonstrates the dangling-else problem.

## Learning Goal
Understand:
- What shift/reduce conflicts are
- The dangling-else problem
- How C resolves if-else ambiguity

## Fix It
Add braces to make the if-else association explicit and clear.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
