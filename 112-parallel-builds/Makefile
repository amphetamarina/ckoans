CC = gcc
CFLAGS = -Wall -Wextra
BUILDDIR = build

SRCS = main.c module1.c module2.c
OBJS = $(SRCS:%.c=$(BUILDDIR)/%.o)

.PHONY: all clean

all: program

# BUG: Missing dependency on BUILDDIR
$(BUILDDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# BUG: Objects might be built before directory exists
program: $(OBJS)
	$(CC) $(OBJS) -o program

# BUG: Multiple things might try to create this simultaneously
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# BUG: Should also depend on generated header
$(BUILDDIR)/main.o: main.c config.h

# BUG: Missing dependency - config.h needs to be generated first
config.h:
	echo "#define VERSION \"1.0\"" > config.h

.PHONY: clean
clean:
	rm -rf program $(BUILDDIR) config.h
