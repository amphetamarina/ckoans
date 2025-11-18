CC = gcc
CFLAGS = -Wall -Wextra

# BUG: Missing -MMD -MP flags for dependency generation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

program: main.o utils.o
	$(CC) main.o utils.o -o program

# BUG: Missing include of dependency files
# Should have: -include main.d utils.d

# BUG: Explicit dependency not listed
# main.o and utils.o both include api.h, but this isn't tracked

.PHONY: clean
clean:
	rm -f program *.o
	# BUG: Should also remove *.d files
