#include "nearest_neighbour.cpp"
#include "structures/Map.h"
#include "structures/Metrics.cpp"

#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;


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


pair <vector <City>, Metrics> bb(const Map &problem) {
    Metrics metrics;
    metrics.start();  // start measuring time;

    vector <vector <int> > distances = problem.getMatrix();

    vector <City> cities = problem.getCities(), greedyPath;
    uint size = cities.size();
    vector<int> city_ids(size);
    
    transform(
        cities.begin(), cities.end(), city_ids.begin(), 
        [] (City city) { return city.id; }
    );


    greedyPath = nearestNeighbour(problem);
    vector <int> curr_solution(1, 1), best_solution(size + 1), left;
    vector <int>::iterator first, last;
    left.reserve(size + 1);

    transform(
        greedyPath.begin(), greedyPath.end(), best_solution.begin(), 
        [] (City city) { return city.id; }
    );

    int upper_bound = problem.computeCostOfPath(best_solution),
        curr_cost, curr_diff;
    int minimum_cost = -lowerBound(problem, city_ids);
    pair <int, vector <int> > curr = make_pair(minimum_cost, curr_solution);
    priority_queue <pair <int, vector <int> > > ref;
    ref.push(curr);
    

    while(not ref.empty()){
            
        // update metrics

        ++metrics.nodes_explored;
        
        if(ref.size() > metrics.max_queue_size){
            metrics.max_queue_size = ref.size();
        }

        // start working

        curr = ref.top();
        ref.pop();

        if(upper_bound > -curr.first){   // upper_bound > current_solution_lower_bound
            curr_solution = curr.second;    
            curr_cost = -curr.first;

            if(curr_solution.size() < size){    // if the solution is not complete yet
                first = curr_solution.begin(), last = curr_solution.end();
                unordered_set<int> visited(first, last);
                
                for(uint i = 0; i < size; ++i){
                    if(visited.find(i + 1) == visited.end()){
                        left.push_back(i + 1);  // push city ids, not indexes
                    }
                }

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
                curr_diff = problem.getDistanceBetween(curr_solution.back(), 1);
                curr_cost += curr_diff - problem.getMinimumDistance(1);  // fix the first edge


                if(curr_cost < upper_bound){
                    curr_solution.push_back(1); // close the path
                    upper_bound = curr_cost;

                    best_solution = curr_solution;
                }

                curr_solution.pop_back();   // remove the loop

            }
        } else {
            ++metrics.times_pruned;
            break;
        }
    }

    transform(
        best_solution.begin(), best_solution.end(), best_solution.begin(), 
        [] (int city_id) { return city_id - 1; }
    );

    permute(cities, best_solution);

    metrics.end();

    return make_pair(cities, metrics);
}