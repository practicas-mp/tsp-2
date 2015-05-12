#include <iostream>
#include <fstream>
#include <string.h>
#include "structures/Map.h"

using namespace std;

double computeCostOfPath(const Map &map, ifstream &route_file){
	string dimension_token;
	int dimension, current_origin_id, current_destination_id;
	double result = 0;

	route_file >> dimension_token;
	route_file >> dimension;

	int first_city_id;
	route_file >> first_city_id;

	current_origin_id = first_city_id;
	route_file >> current_destination_id;

	result += map.getDistanceBetween(current_origin_id, current_destination_id);

	do {
		current_origin_id = current_destination_id;
		route_file >> current_destination_id;

		result += map.getDistanceBetween(current_origin_id, current_destination_id);
	} while (!route_file.eof());

	result += map.getDistanceBetween(current_destination_id, first_city_id); // Close the path

	return result;
}


int main(int argc, char **argv){
	if (argc < 2) {
		cerr << "Error: debe proporcionar el nombre del archivo " << endl;
		return 1;
	}

	char map_file_path[1000];
	char optimum_route_file_path[1000];

	strcpy(map_file_path, argv[1]);
	strcat(map_file_path, ".tsp");
	
	strcpy(optimum_route_file_path, argv[1]);
	strcat(optimum_route_file_path, ".opt.tour");

	ifstream map_file(map_file_path);
	ifstream optimum_route_file(optimum_route_file_path);

	if (map_file.is_open() && optimum_route_file.is_open()){
		
		Map problem(map_file);
		auto cost = computeCostOfPath(problem, optimum_route_file);
		cout << cost << endl;
	} else {
		cerr << "Hubo un error al abrir uno de los archivo de entrada" << endl;
		return 1;
	}

}