#include "structures/Map.h"
#include "nearest_neighbour.cpp"
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;


template <class T> pair <T, T> findMinimums(vector <T> elements){
    T mm = elements[0], m = elements[1];

    for(auto el: elements){
        if(el < mm){
            m = mm;
            mm = el;
        }
    }

    return make_pair(mm, m);
}


template <class T> void permute(vector <T> &elements, vector <int> indices){
    uint i = 0, size = indices.size();
    int aux_index;
    T aux_el;

    while(i < size){
        if(indices[i] == i){
            ++i;
        } else {
            aux_el = elements[i];
            elements[i] = elements[indices[i]];
            elements[indices[i]] = aux_el;

            aux_index = indices[i];
            indices[i] = indices[indices[i]];
            indices[aux_index] = aux_index; 
        }
    }
}


int lowerBound(const vector <int> &left, const vector <vector <int> > &distances){
    int acc = 0;

    for(auto city_id: left){
        acc += findMinimums(distances[city_id]).second;  // first is 0
    }

    return acc;
}


vector <City> bb(const Map &problem) {
    vector <vector <int> > distances = problem.getMatrix();
    vector <City> cities = problem.getCities();
    int size = cities.size(),
        upper_bound = problem.computeCostOfPath(nearestNeighbour(problem)),
        curr_cost, curr_diff;
    vector <int> curr_solution(1, 0), best_solution, left;
    vector <int>::iterator first, last;
    best_solution.reserve(size);
    left.reserve(size);
    pair <int, vector <int> > curr = make_pair(0, curr_solution);
    priority_queue <pair <int, vector <int> > > ref;
    ref.push(curr);

    while(not ref.empty()){
        curr = ref.top();
        ref.pop();

        if(upper_bound > curr.first){
            curr_solution = curr.second;
            curr_cost = problem.computeCostOfPath(curr_solution);

            if(curr_solution.size() < size){
                first = curr_solution.begin(), last = curr_solution.end();

                for(int i = 0; i < size; ++i){
                    if(find(first, last, i) == last){
                        left.push_back(i);
                    }
                }

                curr_cost += lowerBound(left, distances);

                for(auto city_id: left){
                    curr_diff = problem.getDistanceBetween(curr_solution.back() + 1,
                                                            city_id + 1);
                    curr_solution.push_back(city_id);

                    ref.push(make_pair(curr_cost + curr_diff, curr_solution));
                    curr_solution.pop_back();
                }
                
                left.clear();
            } else {  // complete solution
                if(curr_cost < upper_bound){
                    upper_bound = curr_cost;
                    best_solution = curr_solution;
                }
            }
        }
    }

    permute(cities, best_solution);
    return cities;
}