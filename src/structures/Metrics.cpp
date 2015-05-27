#ifndef __METRICS_CPP__
#define __METRICS_CPP__

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;


struct Metrics {
    int nodes_explored, max_queue_size, times_pruned, milliseconds;
    chrono::high_resolution_clock::time_point _start, _end;   

    Metrics(){
        this->nodes_explored = this->max_queue_size = this->times_pruned = 0;
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
    cout << "Nodes explored: " << metrics.nodes_explored << endl;
    cout << "Maximum queue size: " << metrics.max_queue_size << endl;
    cout << "Times pruned: " << metrics.times_pruned << endl;
    cout << "Running time: " << metrics.milliseconds << "ms" << endl;
}

#endif