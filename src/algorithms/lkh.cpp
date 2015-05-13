#include "structures/Map.h"
#include "algorithms/best_insertion.cpp"
#include <algorithm>
#include <limits>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;


vector <City> LKH(const Map &problem){
    srand(time(0));

    vector <City> cities = bestInsertionPath(problem), permutation;
    int size = cities.size(),
        a, b, aux,
        prev_city_a, next_city_a,
        prev_city_b, next_city_b;
    int ITER = size * size + 1;
    double delta;

    while(--ITER){
        a = rand() % size;
        b = rand() % size;
        aux = a;
        a = min(a, b);
        b = max(aux, b);
        prev_city_a = (size + a - 1) % size;
        prev_city_b = (size + b - 1) % size;
        next_city_a = (size + a) % size;
        next_city_b = (size + b) % size;

        delta = problem.getDistanceBetween(
            cities[prev_city_a].id, cities[prev_city_b].id
        );
        delta += problem.getDistanceBetween(
            cities[next_city_a].id, cities[next_city_b].id
        );
        delta -= problem.getDistanceBetween(
            cities[prev_city_a].id, cities[next_city_a].id
        );
        delta -= problem.getDistanceBetween(
            cities[prev_city_b].id, cities[next_city_b].id
        );

        if(delta < 0){
            reverse(
                    cities.begin() + a,
                    cities.begin() + b
            );
        }
    }

    cities.push_back(cities[0]);
    return cities;
}