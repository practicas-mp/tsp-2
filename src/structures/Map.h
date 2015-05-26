#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include <iostream>
#include "City.h"

using namespace std;

class Map {
private:
	vector< vector<int> > distances;
	vector<City> cities;	

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
	void buildMapFromCities(const vector<City> cities);

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

	/**
	 * Gets the cities in the map
	 * @return the cities in the map
	 */
	vector<City> getCities() const;

	/**
	 *	Gets the distance between two cities
	 *	@param first_city_id The id number of the first city
	 *	@param second_city_id The id number of the second city
	 * 	@return the distance between both cities
	 */
	int getDistanceBetween(int first_city_id, int second_city_id) const;

	/**
	 *	Returns the distances matrix of the map
	 * 	@return the matrix
	 */
	const vector <vector <int> >& getMatrix() const;

	/**
	 *	Computes the cost of a given path
	 *	@param cities the cities in the path
	 *	@return the cost of the given path
	 */
	int computeCostOfPath(const vector<City> &cities) const;


	/**
	 *	Computes the cost of a given path
	 *	@param city_ids the ids of the cities in the path
	 *	@return the cost of the given path
	 */
	int computeCostOfPath(const vector<int> &city_ids) const;

};

istream& operator>>(istream &is, Map map);

#include "Map.cpp"

#endif