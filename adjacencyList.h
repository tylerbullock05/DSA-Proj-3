//
// Created by Ross Jackson on 12/3/24.
//
#pragma once

#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <iostream>
#include <iomanip>

using namespace std;

class AdjacencyList {
    private:
        map<string, vector<pair<string, int>>> graph;

    public:
        // Function to add edge with distance in miles being the weight
        void addEdge(string& from, string& to, int distance) {
            graph[from].push_back(make_pair(to, distance));
            if (graph.find(to) == graph.end()) {
                graph[to] = {};
            }
        }
}