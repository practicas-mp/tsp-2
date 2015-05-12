CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./src/structures
BIN = ./bin
OBJ = ./obj


all: $(BIN)/nearest_neighbour $(BIN)/best_insertion

$(BIN)/nearest_neighbour: src/algorithms/nearest_neighbour.cpp
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -D"algorithm=nearestNeighbour" -D"SRC=\"../$<\"" -o $@ 

$(BIN)/best_insertion: src/algorithms/best_insertion.cpp
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -D"algorithm=bestInsertionPath" -D"SRC=\"../$<\"" -o $@ 

install:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

