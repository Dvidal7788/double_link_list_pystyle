# Makefile for double_link.c

# for an executable, no .o files:
# $(CC) -o $(BINARY) $(CFILES)

CC = gcc
CFILES = double_link_func.c main.c
OBJS = double_link_func.o main.o
BIN = bin

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^

run:
	./$(BIN)
clean:
	rm -rf $(BIN)
	rm -rf *.exe
	rm -rf *.o
