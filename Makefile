# Makefile for double_link_list_pystyle

CC = gcc
SRC = src
OBJ = obj
CFILES = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CFILES))
BIN = bin

all:$(BIN)

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) -c $^ -o $@

$(BIN):$(OBJS)
	$(CC) -o $@ $^

run:
	./$(BIN)

clean:
	rm -rf $(BIN)
	rm -rf *.o $(OBJ)/*
	rm -rf *.exe
	rm -rf a.out
