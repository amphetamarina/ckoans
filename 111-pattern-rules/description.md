# Pattern Rules

## Concept
Pattern rules define how to build files matching a pattern:
```make
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

Key concepts:
- `%` matches any non-empty substring (the "stem")
- The stem is the same in target and prerequisites
- Multiple pattern rules can exist
- More specific patterns take precedence

Automatic variables in patterns:
- `$@` - Full target name
- `$<` - First prerequisite
- `$^` - All prerequisites
- `$*` - The stem (matched by `%`)

## What's Broken
The pattern rules are incorrectly written, causing build failures or wrong behavior.

## Learning Goal
Understand:
- How to write pattern rules
- How `%` and `$*` work
- Precedence between pattern rules
- Static pattern rules vs regular pattern rules

## Fix It
Fix the pattern rules to correctly build all targets.

## Verify
```bash
make all
./test1 && ./test2
make clean
```
