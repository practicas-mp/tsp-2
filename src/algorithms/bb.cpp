#include "structures/Map.h"
#include "nearest_neighbour.cpp"
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

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

// ToDo: make in-place
template <class T> void permute(vector <T> &elements, vector <int> indices){
    
    vector<T> result;

    for (auto index : indices) {
        result.push_back(elements[index]);
    }
    
    elements = result;
}


int lowerBound(const Map &problem, const vector <int> &left){
    int acc = 0;

    for(auto city_id: left){
        acc += problem.getMinimumDistance(city_id);
    }

    return acc;
}


vector <City> bb(const Map &problem) {
    vector <vector <int> > distances = problem.getMatrix();

    vector <City> cities = problem.getCities();
    uint size = cities.size();
    vector<int> city_ids(size);
    
    transform(
        cities.begin(), cities.end(), city_ids.begin(), 
        [] (City city) { return city.id; }
    );


    cities = nearestNeighbour(problem);
    vector <int> curr_solution(1, 1), best_solution(size + 1), left;
    vector <int>::iterator first, last;
    // best_solution.reserve(size + 1);
    left.reserve(size + 1);

    transform(
        cities.begin(), cities.end(), best_solution.begin(), 
        [] (City city) { return city.id; }
    );

    int upper_bound = problem.computeCostOfPath(best_solution),
        curr_cost, curr_diff;
    int minimum_cost = -lowerBound(problem, city_ids);
    pair <int, vector <int> > curr = make_pair(minimum_cost, curr_solution);
    priority_queue <pair <int, vector <int> > > ref;
    ref.push(curr);
    

    while(not ref.empty()){
        curr = ref.top();
        ref.pop();

        if(upper_bound > -curr.first){   // upper_bound > current_solution_lower_bound
            curr_solution = curr.second;    

            if(curr_solution.size() < size){    // if the solution is not complete yet
                cout << upper_bound << " " << -curr.first << endl;
                first = curr_solution.begin(), last = curr_solution.end();
                unordered_set<int> visited(first, last);
                
                for(uint i = 0; i < size; ++i){
                    if(visited.find(i + 1) == visited.end()){
                        left.push_back(i + 1);  // push city ids, not indexes
                    }
                }


                curr_cost = -curr.first;

                for(auto city_id: left){
                    int minimum_city_cost = problem.getMinimumDistance(city_id);
                    curr_diff = problem.getDistanceBetween(curr_solution.back(),
                                                            city_id);
                    curr_solution.push_back(city_id);   // city_ids, not indexes

                    ref.push(make_pair(-(curr_cost - minimum_city_cost + curr_diff) , curr_solution));
                    curr_solution.pop_back();
                }
                
                left.clear();
            } else {  // complete solution
                // curr_diff = problem.getDistanceBetween(curr_solution.back(), 1);
                curr_solution.push_back(curr_solution[0]); // close the path
                curr_cost = problem.computeCostOfPath(curr_solution);

                if(curr_cost < upper_bound){
                    cout << "Solucion minima encontrada " << curr_cost << endl;
                    upper_bound = curr_cost;

                    best_solution = curr_solution;
                }

                curr_solution.pop_back();   // remove the loop
            }
        } else {
            cout << "Se debería acabar aquí" << endl;
            break;
        }
    }

    // transform best solution to indexes
    transform(
        best_solution.begin(), best_solution.end(), best_solution.begin(), 
        [] (int city_id) { return city_id - 1; }
    );

    permute(cities, best_solution);

    return cities;
}