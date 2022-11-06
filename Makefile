# Makefile for double_link.c

CC = gcc
CFILES = double_link_func.c main.c
OBJS = double_link_func.o main.o
BIN = bin

all:$(BIN)

$(OBJS):$(CFILES)
	gcc -c $^

$(BIN):$(OBJS)
	gcc -o $@ $^

run:
	./$(BIN)
clean:
	rm -rf $(BIN)
	rm -rf *.exe
	rm -rf *.o
