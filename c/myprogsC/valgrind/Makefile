#Makefile for building demo applications

TARGETS=valgrind

CROSS_TOOL =
CC_CPP = $(CROSS_TOOL)g++
CC_C = $(CROSS_TOOL)gcc

CFLAGS = -Wall -Werror -g -std=c99

all: clean $(TARGETS)

$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@.out

clean:
	rm -f $(TARGETS)
