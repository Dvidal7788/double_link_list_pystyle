# Makefile for double_link_list_pystyle

PROGRAM = dblink-pystyle
CC = gcc
BIN = bin

SRC = src
OBJ = obj
INCDIRS = . ./include

DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)

CFILES = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c,%.o, $(CFILES))
DEPFILES = $(patsubst $(SRC)/%.c,$(OBJ)/%.d, $(CFILES))

DATE = $(shell date +%Y-%m-%d)
TIME = $(shell date +%r)


all:$(BIN)

%.o:$(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $(OBJ)/$@
	@echo $@ created

$(BIN):$(OBJS)
	$(CC) -o $@ $(foreach O,$^,$(OBJ)/$(O))
	@echo $(BIN)\* created $(TIME)

run:
	@./$(BIN)

dist: clean
	tar -czvf $(PROGRAM)_$(DATE).tgz *

clean:
	rm -rf $(BIN)
	rm -rf *.o $(OBJ)/*.o
	rm -rf *.exe a.out
	@echo clean complete $(TIME)

-include $(DEPFILES)
