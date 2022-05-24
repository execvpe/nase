CC = gcc
CFLAGS = -Wall -Wformat=2 -Wshadow -Wconversion -std=c11
RM = rm

.PHONY: all clean

all: nase

clean:
	$(RM) nase

nase: nase.c
	$(CC) $(CFLAGS) -o $@ $^
