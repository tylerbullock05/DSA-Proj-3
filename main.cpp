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

    auto end = chrono::high_resolution_clock::now();
    auto dijkstraTime = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Dijkstra time: " << dijkstraTime.count() << "ms" << endl;

    // Run the Bellman-Ford
    auto start2 = chrono::high_resolution_clock::now();
    // Create instance of dijkstra and perform the algorithm

    auto end2 = chrono::high_resolution_clock::now();
    auto bellmanFordTime = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    cout << "Bellman-Ford time: " << bellmanFordTime.count() << "ms" << endl;


    return 0;
}
