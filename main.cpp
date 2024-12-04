#include "parseCSV.h"
#include "adjacencyList.h"
#include <vector>
#include <iostream>

#include "adjacencyList.h"

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
    cout<<"done"<<endl;

    // Print out the graph
    cout << "Graph: \n";
    graph.printGraph();

    return 0;
}
