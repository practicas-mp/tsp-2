CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
BIN = ./bin
OBJ = ./obj


all: $(BIN)/nearest_neighbour


bin/nearest_neighbour: $(SRC)/structures/Map.h $(SRC)/structures/City.h $(SRC)/structures/Map.cpp $(SRC)/algorithms/nearest_neighbour.cpp $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -o bin/nearest_neighbour



install:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

