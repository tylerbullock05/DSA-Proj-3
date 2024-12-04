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
    cout<<"done"<<endl;

    return 0;
}
