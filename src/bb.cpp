#include "algorithms/bb.cpp"
#include "structures/Map.h"
#include "structures/Metrics.cpp"

#include <fstream>
#include <iostream>
#include <string.h>
#include <set>

using namespace std;


int main(int argc, char **argv){
    if (argc < 3) {
        cerr << "Error: debe proporcionar el nombre del archivo y [path|cost]" << endl;
        return 1;
    }

    ifstream input_file(argv[1]);

    if (input_file.is_open()){
        Map problem(input_file);
        auto solution = bb(problem);

        if (strcmp(argv[2], "path") == 0){
            cout << solution.first;
            cout << solution.second;         
        } else {
            cout << problem.computeCostOfPath(solution.first) << endl;
        }

    } else {
        cerr << "Hubo un error al abrir el archivo de entrada" << endl;
        return 1;
    }

}