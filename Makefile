CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
BIN = ./bin
OBJ = ./obj


all: obj/Map.o



obj/Map.o: $(INCLUDE)/Map.h $(SRC)/Map.cpp
	 $(CC) $(CPPFLAGS) -c $(SRC)/Map.cpp -o obj/Map.o


install:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

