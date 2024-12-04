#include "parseCSV.h"
vector<vector<string>> parseCSV::parseData(std::string fileName) {
    ifstream file(fileName); // Open your CSV file
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        vector<string> temp;
        while (std::getline(ss, field, ',')) { // Split by commas
            temp.push_back(field);
        }
        flights.push_back(temp);
        temp.clear();
    }

    file.close();
    return flights;
}
