#include "parseCSV.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    parseCSV file;
    vector<vector<string>> f = file.parseData("USAAirlinesRoutes.csv");
    for(auto flights : f)
    {
        cout<<flights[0]<<" to "<<flights[1]<<" has a distance of "<<flights[2]<<" miles"<<endl;
    }

    return 0;
}
