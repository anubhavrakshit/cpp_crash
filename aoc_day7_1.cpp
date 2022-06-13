#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <map>
using namespace std;


int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> crab_table;
    

    for (int i; ss >> i; ) {
        crab_table.push_back(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    cout << "Crab Table = " << crab_table.size() << endl;
    sort(crab_table.begin(), crab_table.end());

    int median_index = crab_table.size() / 2; 
    int median_value = crab_table[median_index];

    int total_dist{0};

    for (auto dist : crab_table) {
        total_dist += abs(dist - median_value);
    }

    cout << "Ans = " << total_dist << endl;

    return 0;
}