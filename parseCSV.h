#ifndef DSA_PROJ_3_PARSECSV_H
#define DSA_PROJ_3_PARSECSV_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class parseCSV {
public:
    vector<vector<string>>  flights;
    vector<vector<string>> parseData(string fileName);
};


#endif //DSA_PROJ_3_PARSECSV_H
