# BUG: Wrong variable names - should use CC, CFLAGS, LDFLAGS
COMPILER = gcc
COMPILER_FLAGS = -Wall -Wextra
LINKER_FLAGS = -lm

# BUG: Explicit rule that fights with implicit rules
program.o: program.c
	$(COMPILER) $(COMPILER_FLAGS) -c program.c -o program.o

# BUG: Wrong automatic variable usage
program: program.o
	$(COMPILER) $< $(LINKER_FLAGS) -o $<

# BUG: Missing .PHONY declaration
clean:
	rm -f program program.o

# BUG: Should declare all and clean as phony targets
all: program
