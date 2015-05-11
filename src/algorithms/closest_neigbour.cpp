#include "structures/Map.h"
#include <vector>
#include <set>

using namespace std;

vector<City> closestNeighbour(Map problem) {
	vector<City> cities = problem.getCities();

	for(int i = 0; i < cities.size() - 1; i++){
		
		double minimum_distance = cities[i].distanceTo(cities[i + 1]);
		int closest_neigbour_index = i + 1;

		// find the closest neighbour
		for(int j = i + 1; j < cities.size(); j++){
			if (cities[i].distanceTo(cities[j]) < minimum_distance){
				closest_neigbour_index = j;
				minimum_distance = cities[i].distanceTo(cities[j]);;
			}
		}

		// swap next city with closest neighbour
		City aux = cities[i + 1];
		cities[i + 1] = cities[closest_neigbour_index];
		cities[closest_neigbour_index] = aux;
	}

	cities.push_back(cities[0]); // Return to the first city

	return cities;
}