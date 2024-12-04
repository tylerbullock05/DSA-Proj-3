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
#include <queue>
#include <unordered_map>
#include <limits>
#include <set>
using namespace std;

class AdjacencyList {
    private:
        map<string, vector<pair<string, int>>> graph;
        set<string> uniqueAirports;
        int numAirports = 0;
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
            if(uniqueAirports.insert(from).second)
                numAirports++;
            if(uniqueAirports.insert(to).second)
                numAirports++;
        }
        void printGraph() const {
            for (const auto& [node, neighbors] : graph) {
                cout << "Airport " << node << " connects to:\n";
                for (const auto& [neighbor, distance] : neighbors) {
                    cout << "  - " << neighbor << " (" << distance << " miles)\n";
                }
            }
        }

        // Dijkstra's Algorithm
        int dijkstra(const string& start, const string& destination) {
            // Priority queue to hold nodes based on their current shortest distance
            priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

            // Map to store the shortest distance to each node
            unordered_map<string, int> distances;

            // Initialize distances to infinity
            for (const auto& [node, _] : graph) {
                distances[node] = numeric_limits<int>::max();
            }
            distances[start] = 0;

            pq.push({0, start});

            while (!pq.empty()) {
                auto [currentDistance, currentNode] = pq.top();
                pq.pop();

                // If the arrival airport is found, return the distance
                if (currentNode == destination) return currentDistance;

                // If the current distance to the arrival airport is greater than the existing distance, ignore and start again
                if (currentDistance > distances[currentNode]) continue;

                // Update the distances to the neighbors
                for (const auto& [neighbor, weight] : graph[currentNode]) {
                    int newDistance = currentDistance + weight;
                    if (newDistance < distances[neighbor]) {
                        distances[neighbor] = newDistance;
                        pq.push({newDistance, neighbor});
                    }
                }
            }

            return -1; // Return -1 if the destination is unreachable
        }

        // Bellman-Ford Algorithm
        int bellmanFord(const string& start, const string& destination) {
            // Stores the shortest distance to each node
            unordered_map<string, int> distances;

            // Initialize distances to infinity
            for (const auto& [node, _] : graph) {
                distances[node] = numeric_limits<int>::max();
            }
            distances[start] = 0;

            // Relax edges
            for (size_t i = 0; i < graph.size() - 1; ++i) {
                for (const auto& [node, neighbors] : graph) {
                    for (const auto& [neighbor, weight] : neighbors) {
                        if (distances[node] != numeric_limits<int>::max() &&
                            distances[node] + weight < distances[neighbor]) {
                            distances[neighbor] = distances[node] + weight;
                        }
                    }
                }
            }

            // Check for negative-weight cycles
            for (const auto& [node, neighbors] : graph) {
                for (const auto& [neighbor, weight] : neighbors) {
                    if (distances[node] != numeric_limits<int>::max() &&
                        distances[node] + weight < distances[neighbor]) {
                        return -1;
                    }
                }
            }

            return distances[destination] == numeric_limits<int>::max() ? -1 : distances[destination];
        }
        set<string> getAirports(){
            return uniqueAirports;
        };

};
