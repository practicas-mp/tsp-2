#ifndef __CITY_H__
#define __CITY_H__
#include <cmath>
#include <iostream>

using namespace std;

struct Position {
	double x;
	double y;

	Position() : x(0), y(0) {}	// Avoid garbage

	Position(double x, double y) : x(x), y(y) {}
};


struct City {
	int id;
	Position position;

	City(int id, Position position) : id(id), position(position) {}

	City(int id, double x, double y) : id(id), position(Position(x, y)) {}

	City() : id(-1) {}	// No garbage

	int distanceTo(const City &other) const;
};

int City::distanceTo(const City &other) const {
	double horizontal_component = (position.x - other.position.x)*(position.x - other.position.x);
	double vertical_component = (position.y - other.position.y)*(position.y - other.position.y);

	return sqrt(horizontal_component + vertical_component) + 0.5;	// round to the closest integer
}


istream& operator>>(istream& is, City &city){
	double x, y;
	int id;

	is >> id;
	is >> x;
	is >> y;

	city.id = id;
	city.position = Position(x, y);

	return is;
}

ostream& operator<<(ostream &os, const City &city){
	os << city.id << "\t" << city.position.x << "\t" << city.position.y;

	return os;
}

istream& operator>>(istream &is, vector<City> &cities){
	string garbage;
	int dimension;

	is >> garbage;
	is >> dimension;

	for(int i = 0; i < dimension; i++){
		City current;
		is >> current;
		cities.push_back(current);
	}

	return is;
}

ostream& operator<<(ostream &os, const vector<City> &cities){
	os << "Dimension: " << cities.size() << endl;

	for(auto city : cities){
		os << city << endl;
	}

	return os;
}


#endif