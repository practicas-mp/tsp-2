#include "Map.h"
#include <cassert>

void Map::adjustSizeOfDistanceMatrix(){
	assert(cities.size() > 0);

	int n = cities.size();
	distances.resize(n);

	for(int i = 0; i < n; i++)
		distances[i].resize(n);

}

void Map::computeDistanceMatrix(){
	this->adjustSizeOfDistanceMatrix();
	
	for(int i = 0; i < cities.size(); i++) {
		for(int j = 0; j <= i; j++) {	// It's symmetric
			double distance = cities[i].distanceTo(cities[j]);
			distances[i][j] = distances[j][i] = distance;
		}
	}
}

void Map::buildMapFromCities(const vector<City> &cities){
	for(auto city : cities){
		this->cities[city.id] = city;
	}

	this->computeDistanceMatrix();
}

Map::Map(const vector<City> &cities){
	this->buildMapFromCities(cities);
}

Map::Map(istream &is) {
	vector<City> cities;
	is >> cities;
	this->buildMapFromCities(cities);
}