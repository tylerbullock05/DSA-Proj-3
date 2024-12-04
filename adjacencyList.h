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
        void addEdge(const string& from, const string& to, int distance) {
            // Check to see if already added
            auto& neighbors = graph[from];
            for (const auto& neighbor : neighbors) {
                if (neighbor.first == to) {
                    // Edge already exists, so return without adding it again
                    return;
                }
            }
            graph[from].push_back(make_pair(to, distance));
            if (graph.find(to) == graph.end()) {
                graph[to] = {};
            }
        }

        void printGraph() const {
            for (const auto& [node, neighbors] : graph) {
                cout << "Airport " << node << " connects to:\n";
                for (const auto& [neighbor, distance] : neighbors) {
                    cout << "  - " << neighbor << " (" << distance << " miles)\n";
                }
            }
        }
};