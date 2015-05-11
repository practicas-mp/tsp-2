#include "Map.h"
#include <cassert>
#include <algorithm>

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

void Map::buildMapFromCities(const vector<City> cities){
	this->cities = cities;

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

vector<City> Map::getCities(){
	return cities;
}

double Map::getDistanceBetween(int first_city_id, int second_city_id){
	return this->distances[first_city_id][second_city_id];
}