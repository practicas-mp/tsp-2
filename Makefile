CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./src/structures
COMMON = src/structures/Map.cpp src/structures/Map.h src/structures/City.h
MAIN = src/main.cpp
BIN = ./bin
OBJ = ./obj

all: $(BIN)/nearest_neighbour $(BIN)/best_insertion $(BIN)/optimum-cost

$(BIN)/nearest_neighbour: src/algorithms/nearest_neighbour.cpp $(COMMON) $(MAIN)
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -D"algorithm=nearestNeighbour" -D"SRC=\"../$<\"" -o $@ 

$(BIN)/best_insertion: src/algorithms/best_insertion.cpp $(COMMON) $(MAIN)
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -D"algorithm=bestInsertionPath" -D"SRC=\"../$<\"" -o $@ 

$(BIN)/optimum-cost: src/optimum-cost.cpp $(COMMON)
	$(CC) $(CPPFLAGS) $(SRC)/optimum-cost.cpp -o $@ 	

compare: all
	./scripts/compare-algorithms.py

install:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -f $(OBJ)/*
	rm -f $(bin)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all install clean mrproper

