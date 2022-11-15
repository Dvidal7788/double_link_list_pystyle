# Makefile for double_link_list_pystyle

CC = gcc
BIN = bin

SRC = src
OBJ = obj
INCDIRS = . ./include

DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)

CFILES = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c,%.o, $(CFILES))
DEFILES = $(patsubst $(SRC)/%.c,$(OBJ)/%.d, $(CFILES))

all:$(BIN)

%.o:$(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $(OBJ)/$@

$(BIN):$(OBJS)
	$(CC) -o $@ $(foreach O,$^,$(OBJ)/$(O))

run:
	./$(BIN)
	
distribute: clean
	tar zcvf dist.tgz *

clean:
	rm -rf $(BIN)
	rm -rf *.o $(OBJ)/*.o
	rm -rf *.exe a.out

-include $(DEPFILES)
