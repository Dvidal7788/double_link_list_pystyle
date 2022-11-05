# Makefile for double_link.c

# for an executable, no .o files:
# $(CC) -o $(BINARY) $(CFILES)

CC = gcc
BINARY = bin
CFILES = double_link_func.c main.c
OBJECTS = double_link_func.o main.o

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

run:
	./$(BINARY)
clean:
	rm -rf $(BINARY)
	rm -rf *.exe
	rm -rf *.o
