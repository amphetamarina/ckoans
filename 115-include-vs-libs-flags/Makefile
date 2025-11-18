CC = gcc
CFLAGS = -Wall -Wextra

# BUG: Using --libs for compilation flags
COMPILE_FLAGS = $(shell pkg-config --libs mathlib)

# BUG: Using --cflags for linking flags
LINK_FLAGS = $(shell pkg-config --cflags mathlib)

program: program.o
	# BUG: Should use --libs here, not --cflags
	$(CC) program.o $(LINK_FLAGS) -o program

# BUG: Should use --cflags here, not --libs
program.o: program.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c program.c -o program.o

.PHONY: clean
clean:
	rm -f program program.o
