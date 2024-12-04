#include "parseCSV.h"
#include "adjacencyList.h"
#include <vector>
#include <iostream>
#include <chrono>

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

    // gives user option to look at available airport codes
    set<string> airports = graph.getAirports();

    while (true) {
        // Welcome screen and options
        cout << "\nWeclome to our USA Airline Flight Route Finder!" << endl;
        cout << "   1. To print the adjacency list of the data" << endl;
        cout << "   2. To explore available airports" << endl;
        cout << "   3. To see direct flights" << endl;
        cout << "   4. To find the best path between two airports utilizing Dijkstra's Algorithm and Bellman-Ford's Algorithm" << endl;
        cout << "   5. Exit" << endl;
        cout << endl << "Enter a valid number (will only read the first character): ";
        char number;
        cin >> number;
        cout << endl;

        if (!isdigit(number)) {
            cout << "Input not valid, please retry:" << endl;
            continue;
        }

        int number2 = number - '0';
        if (number2 > 5 || number2 < 1) {
            cout << "Input not valid, please retry:" << endl;
            continue;
        }

        if (number2 == 1) {
            graph.printGraph();
            cout << "\nPress the enter key to continue: ";
            cin.ignore();
            cin.get();
        }
        else if (number2 == 2) {
            while(true)
            {
                cout<< "Enter one capital letter to see what airport codes start with that letter\n"
                       "To return to options screen, type any number or symbol: ";
                char letter;
                cin>>letter;
                cout<<endl;
                if(!isalpha(letter))        // checks if number is alphabetical
                    break;
                for(auto it = airports.begin(); it != airports.end(); it++) {
                    if(it->at(0) == letter)     // check if first letter matches inputted letter
                        cout<<*it<<" | ";
                }
                cout<<endl<<endl;
            }
        }

        else if(number2 == 3) {
            while(true) {
                cout << "\nTo go back to welcome screen, type 'RETURN': " << endl;
                cout << "Enter in all caps an airport code: ";

                string airportCode;
                cin >> airportCode;
                if(airportCode == "RETURN") {
                    break;
                }
                else {
                    cout << endl;
                    graph.printDirect(airportCode);
                }
                //cout << "\nPress enter key to continue: ";
                //cin.ignore();
                //cin.get();
            }
        }

        else if (number2 == 4) {
            // Ask user for inputs of airport codes
            string origin;
            string destination;
            cout << "Enter the origin airport code in all caps: ";
            cin >> origin;
            cout << "Enter the destination airport code in all caps: ";
            cin >> destination;
            // Check to see if it exists
            int originExists = graph.codeExists(origin);
            int destinationExists = graph.codeExists(destination);

            // Run the two algorithms and start the clocks
            auto start = chrono::high_resolution_clock::now();
            // Create instance of dijkstra and perform the algorithm
            int dijkstraDistance = graph.dijkstra(origin, destination);

            auto end = chrono::high_resolution_clock::now();
            auto dijkstraTime = chrono::duration_cast<chrono::microseconds>(end - start);
            // If a path exists, print the shortest distance
            if (dijkstraDistance != -1) {
                cout << endl << "Dijkstra's Algorithm: Shortest distance from " << origin << " to " << destination << " is " << dijkstraDistance << " miles." << endl;
            }
            else {
                cout << endl << "Dijkstra's Algorithm: No path exists from " << origin << " to " << destination << "." << endl;
            }
            cout << "Dijkstra time: " << dijkstraTime.count() << " microseconds" << endl;

            // Run the Bellman-Ford
            auto start2 = chrono::high_resolution_clock::now();
            // Create instance of bellman ford and perform the algorithm
            int bellmanFordDistance = graph.bellmanFord(origin, destination);

            auto end2 = chrono::high_resolution_clock::now();
            auto bellmanFordTime = chrono::duration_cast<chrono::microseconds>(end2 - start2);
            // If a path exists, print the shortest distance
            if (originExists == 1 || destinationExists == 1) {
                cout << endl << "Bellman-Ford Algorithm: No path exists from " << origin << " to " << destination << "." << endl;
            }
            else if (bellmanFordDistance != -1) {
                cout << endl << "Bellman-Ford Algorithm: Shortest distance from " << origin << " to " << destination << " is " << bellmanFordDistance << " miles." << endl;
            } else if(origin != destination){
                cout << endl << "Bellman-Ford Algorithm: No path exists from " << origin << " to " << destination << "." << endl;
            }
            cout << "Bellman-Ford time: " << bellmanFordTime.count() << " microseconds" << endl;

            cout << "\nPress the enter key to continue: ";
            cin.ignore();
            cin.get();
        }

        else if (number2 == 5) {
            cout << "Exiting..." << endl;
            return 0;
        }

    }
    return 0;
}
