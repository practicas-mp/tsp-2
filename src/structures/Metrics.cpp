#ifndef __METRICS_CPP__
#define __METRICS_CPP__

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;


struct Metrics {
    int nodes_explored, max_queue_size, times_pruned, milliseconds, complete_paths;
    chrono::high_resolution_clock::time_point _start, _end;   

    Metrics(){
        this->complete_paths = this->nodes_explored = this->max_queue_size = this->times_pruned = 0;
    }

    void start(){
        this->_start = chrono::high_resolution_clock::now();
    }

    // TODO: make sure start has been called first
    void end(){
        this->_end = chrono::high_resolution_clock::now();
        this->milliseconds = chrono::duration_cast <chrono::milliseconds> (this->_end - this->_start).count();
    }
};


ostream& operator<<(ostream& os, const Metrics &metrics){
    os << "Nodes explored: " << metrics.nodes_explored << endl;
    os << "Maximum queue size: " << metrics.max_queue_size << endl;
    os << "Times pruned: " << metrics.times_pruned << endl;
    os << "Running time: " << metrics.milliseconds << "ms" << endl;
    os << "Complete paths reached: " << metrics.complete_paths << endl;

    return os;
}

#endif