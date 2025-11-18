# Dependency Inference

## Concept
Make needs to know which source files depend on which headers. Without this:
- Changes to headers don't trigger recompilation
- Builds may use stale object files
- Results are incorrect

GCC can auto-generate dependencies:
- `-MMD` - Generate dependency file
- `-MP` - Add phony targets for headers
- `-MF file` - Write dependencies to file

Pattern:
```make
DEPS := $(OBJS:.o=.d)
-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
```

## What's Broken
The Makefile doesn't track header dependencies, causing stale builds.

## Learning Goal
Understand:
- Why header dependencies matter
- How to auto-generate dependencies with `-MMD -MP`
- How to include generated dependency files

## Fix It
Add dependency inference using `-MMD -MP` and include the generated `.d` files.

## Verify
```bash
make
./program
diff <(./program) expected.txt
# Test that changing header triggers rebuild
touch config.h
make
```
