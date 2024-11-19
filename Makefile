CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/arvoreBinaria.c src/livro.c
OUT = bin/programa.exe

all: $(SRC)
	$(CC) -o $(OUT) $(SRC)

clean:
	rm bin/*
