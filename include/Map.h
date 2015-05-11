#ifndef __MAP_H__
#define __MAP_H__

#include <unordered_map>
#include <vector>
#include <iostream>
#include "City.h"

using namespace std;

class Map {
private:
	vector< vector<double> > distances;
	unordered_map<int, City> cities;	//< City id -> city

	/**
	 *	This functions adjusts the size of the distance matrix
	 */
	 void adjustSizeOfDistanceMatrix();

	/**
	 *	Function that computes the distance matrix of the cities in the map
	 */
	void computeDistanceMatrix();

	/**
	 *	Sets the internal state for a Map with a certain vector of cities
	 * 	@param cities vector containing the wanted cities for the map
	 */
	void buildMapFromCities(const vector<City> &cities);

public:
	/**
	 *	Constructor of the Map class
	 *	@param cities Un vector con las ciudades del mapa
	 */
	 Map(const vector<City> &cities);

	/**
	 *	Build a map from an input stream
	 */
	 Map(istream &is);


};

istream& operator>>(istream &is, Map map);

#endif