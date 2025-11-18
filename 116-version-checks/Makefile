CC = gcc
CFLAGS = -Wall -Wextra

# BUG: Wrong version comparison operator (should be >=)
HAS_JSONLIB := $(shell pkg-config --exists "jsonlib > 1.0" && echo yes)
ifneq ($(HAS_JSONLIB),yes)
$(error jsonlib version >= 1.0 is required)
endif

# BUG: Using wrong pkg-config command for version check
MIN_VERSION = 1.5
VERSION_CHECK := $(shell pkg-config --modversion jsonlib)
ifneq ($(VERSION_CHECK),$(MIN_VERSION))
# BUG: This checks for exact match, not minimum version
$(error jsonlib version must be at least $(MIN_VERSION))
endif

# BUG: Querying flags without checking if package exists first
CFLAGS += $(shell pkg-config --cflags jsonlib)
LIBS = $(shell pkg-config --libs jsonlib)

program: program.o
	$(CC) program.o $(LIBS) -o program

program.o: program.c
	$(CC) $(CFLAGS) -c program.c -o program.o

.PHONY: clean
clean:
	rm -f program program.o
