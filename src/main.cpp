/*
	SRC and algorithm are defined in compilation time in the makefile
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include "structures/Map.h"
#include <set>
#include SRC

using namespace std;

int main(int argc, char **argv){
	if (argc < 3) {
		cerr << "Error: debe proporcionar el nombre del archivo y [path|cost]" << endl;
		return 1;
	}

	ifstream input_file(argv[1]);


	if (input_file.is_open()){
		Map problem(input_file);
		auto solution = algorithm(problem);

		if (strcmp(argv[2], "path") == 0){
			cout << solution;			
		} else {
			cout << problem.computeCostOfPath(solution) << endl;
		}

	} else {
		cerr << "Hubo un error al abrir el archivo de entrada" << endl;
		return 1;
	}

}