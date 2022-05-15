CC = gcc

.PHONY: all clean

all: nase

clean:
	rm nase

nase: nase.c
	$(CC) -o nase nase.c
