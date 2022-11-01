# Makefile for double_link.c

CC = gcc
OBJ = double_link

all:
	$(CC) -o $(OBJ) double_link.c
run:
	./double_link
clean:
	rm double_link