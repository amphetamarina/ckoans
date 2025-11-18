CC = gcc
CFLAGS = -Wall -Wextra

TESTS = test1 test2

.PHONY: all clean

all: $(TESTS)

# BUG: Wrong automatic variable - should use $< for first prerequisite
%.o: %.c
	$(CC) $(CFLAGS) -c $@ -o $@

# BUG: Wrong pattern - doesn't match the stem correctly
test%: test.o
	$(CC) $^ -o $@

# BUG: This pattern rule is too broad and conflicts
%: %.o
	$(CC) $< -o $*

.PHONY: clean
clean:
	rm -f $(TESTS) *.o
