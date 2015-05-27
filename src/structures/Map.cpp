#include "Map.h"
#include <cassert>
#include <algorithm>
#include <limits>
#include <set>

void Map::adjustSizeOfDistanceMatrix(){
	assert(cities.size() > 0);

	int n = cities.size();
	distances.resize(n);

	for(int i = 0; i < n; i++)
		distances[i].resize(n);

}

void Map::computeDistanceMatrix(){
	this->adjustSizeOfDistanceMatrix();
	
	for(uint i = 0; i < cities.size(); i++) {
		for(uint j = 0; j <= i; j++) {	// It's symmetric
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

vector<City> Map::getCities() const {
	return cities;
}

int Map::getDistanceBetween(int first_city_id, int second_city_id) const {
	return this->distances[first_city_id - 1][second_city_id - 1];  // ids go from 1 to N
}

int Map::getMinimumDistance(int city_id) const {
	uint size = this->distances.size(), i = 0;
	int min_dist = numeric_limits <int>::max();

	while(++i < size){
		if(min_dist > this->distances[city_id - 1][i] and city_id - 1 != i){
			min_dist = this->distances[city_id - 1][i];
		}
	}

	return min_dist;
}

const vector <vector <int> >& Map::getMatrix() const {
	return this->distances;
}

int Map::computeCostOfPath(const vector<City> &cities) const {
	
	vector<int> city_ids(cities.size());

	// cool c++11 lambdas magic ;)
	transform(cities.begin(), cities.end(), city_ids.begin(), [] (City city) {
		return city.id;
	});

	return this->computeCostOfPath(city_ids);
}

int Map::computeCostOfPath(const vector<int> &city_ids) const {
	
	double result = 0;
	
	for(uint i = 0; i < city_ids.size() - 1; i++){
		result += this->getDistanceBetween(city_ids[i], city_ids[i + 1]);
	}

	return result;
}