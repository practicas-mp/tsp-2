/*
	SRC and algorithm are defined in compilation time in the makefile
*/
#include <iostream>
#include <fstream>
#include "structures/Map.h"
#include SRC

using namespace std;

int main(int argc, char **argv){
	if (argc < 2) {
		cerr << "Error: debe proporcionar el nombre del archivo " << endl;
		return 1;
	}

	ifstream input_file(argv[1]);

	if (input_file.is_open()){
		Map problem(input_file);

		auto solution = algorithm(problem);

		cout << solution;
	} else {
		cerr << "Hubo un error al abrir el archivo de entrada" << endl;
		return 1;
	}

}