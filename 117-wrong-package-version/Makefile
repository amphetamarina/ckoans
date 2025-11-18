CC = gcc
CFLAGS = -Wall -Wextra

# BUG: Requires version 3.0, but installed version is only 2.5
REQUIRED_VERSION = 3.0

# This will fail because the version is too old
HAS_WEBLIB := $(shell pkg-config --atleast-version=$(REQUIRED_VERSION) weblib && echo yes)

ifneq ($(HAS_WEBLIB),yes)
$(error weblib >= $(REQUIRED_VERSION) required, but found $(shell pkg-config --modversion weblib 2>/dev/null || echo "not found"))
endif

CFLAGS += $(shell pkg-config --cflags weblib)
LIBS = $(shell pkg-config --libs weblib)

program: program.o
	$(CC) program.o $(LIBS) -o program

program.o: program.c
	$(CC) $(CFLAGS) -c program.c -o program.o

.PHONY: clean
clean:
	rm -f program program.o

.PHONY: version-info
version-info:
	@echo "Required version: $(REQUIRED_VERSION)"
	@echo "Installed version: $(shell pkg-config --modversion weblib 2>/dev/null || echo "NOT FOUND")"
	@pkg-config --exists weblib && echo "Package exists" || echo "Package NOT found"
