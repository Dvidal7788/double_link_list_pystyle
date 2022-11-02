# Makefile for double_link.c

CC = gcc
OBJ = double_link

double_link: double_link.c
	$(CC) -o $(OBJ) double_link_func.c double_link.c
run:
	./$(OBJ)
clean:
	rm $(OBJ)
	rm -rf *.exe
	rm -rf *.o