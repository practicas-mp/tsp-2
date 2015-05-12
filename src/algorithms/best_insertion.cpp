#include "structures/Map.h"
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;


pair <int, double> bestPlace(const Map &problem, const vector <City> &partial, const City &candidate){
    int size = partial.size();
    double curr_incr;
    vector <double> increments(size);

    for(int i = 0; i < size; ++i){
        curr_incr = problem.getDistanceBetween(partial[(size + i - 1) % size].id, candidate.id);
        curr_incr += problem.getDistanceBetween(partial[i].id, candidate.id);
        curr_incr -= problem.getDistanceBetween(partial[(size + i - 1) % size].id, partial[i].id);
        increments.push_back(curr_incr);
    }

    vector <double>::iterator min_el = min_element(increments.begin(), increments.end());
    pair <int, double> sol(min_el - increments.begin(), *min_el);
    return sol;
}


bool sortInsertionPairs(pair <int, double> a, pair <int, double> b){
    return a.second < b.second or (a.second == b.second and a.first < b.first);
}


pair <int, int> bestInsertion(const Map &problem, const vector <City> &partial, const vector <City> &left){
    int size = partial.size();
    vector <pair <int, double> > increments(size);

    for(int i = 0; i < size; ++i){
        increments.push_back(bestPlace(problem, partial, left[i]));
    }

    vector <pair <int, double> >::iterator min_el = min_element(increments.begin(), increments.end(), sortInsertionPairs);
    pair <int, int> sol(min_el->first, min_el - increments.begin());
    return sol;
}


vector <City> bestInsertionPath(const Map &problem){
    vector <City> cities = problem.getCities(), partial;
    partial.push_back(cities[0]);  // TODO: check solution for every starting city
    partial.push_back(cities[1]);  // nearest or farthest?
    cities.erase(cities.begin(), cities.begin() + 2);
    pair <int, int> best_insert;

    while(not cities.empty()){
        best_insert = bestInsertion(problem, partial, cities);
        partial.insert(partial.begin() + best_insert.first, cities[best_insert.second]);
        cities.erase(cities.begin() + best_insert.second);
    }

    return partial;
}

