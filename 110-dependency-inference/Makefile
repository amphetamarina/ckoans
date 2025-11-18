CC = gcc
CFLAGS = -Wall -Wextra

# BUG: No dependency tracking
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

program: $(OBJS)
	$(CC) $(OBJS) -o program

# BUG: Missing header dependencies
# If config.h or utils.h changes, objects won't rebuild
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c -o utils.o

# BUG: Missing dependency file inclusion
# Should include auto-generated .d files

.PHONY: clean
clean:
	rm -f program $(OBJS)
	# BUG: Should also remove .d files
