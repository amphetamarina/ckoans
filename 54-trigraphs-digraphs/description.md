# Trigraphs and Digraphs

## Concept
**Trigraphs** and **digraphs** are alternative representations for characters that might not be available on all keyboards (historical compatibility).

**Trigraphs** (3-character sequences starting with `??`):
- `??=` → `#`
- `??/` → `\`
- `??'` → `^`
- `??(` → `[`
- `??)` → `]`
- `??!` → `|`
- `??<` → `{`
- `??>` → `}`
- `??-` → `~`

**Digraphs** (2-character sequences):
- `<:` → `[`
- `:>` → `]`
- `<%` → `{`
- `%>` → `}`
- `%:` → `#`
- `%:%:` → `##`

Trigraphs are processed in translation phase 1 (before preprocessing). Digraphs are tokens.

**Note**: Trigraphs are removed in C23, deprecated in C++17.

## What's Broken
The code uses trigraphs/digraphs but incorrectly, or has unintended trigraph sequences.

## Learning Goal
Understand:
- What trigraphs and digraphs are
- When they're processed
- How they can cause unexpected behavior

## Fix It
Replace trigraphs/digraphs with regular characters or fix unintended sequences.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
