#include "parseCSV.h"
#include "adjacencyList.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    parseCSV file;
    AdjacencyList graph;
    vector<vector<string>> flights = file.parseData("USAAirlinesRoutes.csv");
    for(auto flight : flights)
    {
        graph.addEdge(flight[0],flight[1],stoi(flight[2]));
    }
    // cout<<"done"<<endl;

    // Print out the graph
    cout << "Graph: " << endl;
    graph.printGraph();

    // Ask user for inputs of airport codes
    string origin;
    string destination;
    cout << endl << "Enter the origin airport code in all caps: " << endl;
    cin >> origin;

    cout << "Enter the destination airport code in all caps: " << endl;
    cin >> destination;

    // Run the two algorithms and start the clocks
    auto start = chrono::high_resolution_clock::now();
    // Create instance of dijkstra and perform the algorithm
    int dijkstraDistance = graph.dijkstra(origin, destination);

    auto end = chrono::high_resolution_clock::now();
    auto dijkstraTime = chrono::duration_cast<chrono::milliseconds>(end - start);
    // If a path exists, print the shortest distance
    if (dijkstraDistance != -1) {
        cout << "Dijkstra's Algorithm: Shortest distance from " << origin << " to " << destination << " is " << dijkstraDistance << " miles." << endl;
    }
    else {
        cout << "Dijkstra's Algorithm: No path exists from " << origin << " to " << destination << "." << endl;
    }
    cout << "Dijkstra time: " << dijkstraTime.count() << "ms" << endl;

    // Run the Bellman-Ford
    auto start2 = chrono::high_resolution_clock::now();
    // Create instance of bellman ford and perform the algorithm
    int bellmanFordDistance = graph.bellmanFord(origin, destination);
    
    auto end2 = chrono::high_resolution_clock::now();
    auto bellmanFordTime = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    // If a path exists, print the shortest distance
    if (bellmanFordDistance != -1) {
        cout << "Bellman-Ford Algorithm: Shortest distance from " << origin << " to " << destination << " is " << bellmanFordDistance << " miles." << endl;
    } else {
        cout << "Bellman-Ford Algorithm: No path exists from " << origin << " to " << destination << "." << endl;
    }
    cout << "Bellman-Ford time: " << bellmanFordTime.count() << "ms" << endl;

    return 0;
}
