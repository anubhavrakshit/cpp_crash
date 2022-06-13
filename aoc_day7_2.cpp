#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int calc_fuel(int base_pos, int cur_pos) {
    int dist = abs(base_pos - cur_pos);
    auto fuel_cons = (dist * (dist + 1)) / 2;
    return fuel_cons;
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> crab_table;

    int max_horizontal_dist{0}; 
    for (int i; ss >> i; ) {
        max_horizontal_dist = max(max_horizontal_dist, i);
        crab_table.push_back(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    int num_crabs = crab_table.size();
    vector<vector<int>> fuel_table(num_crabs, vector<int>(max_horizontal_dist + 1, 0));

    for (int i = 0; i < crab_table.size(); i++) {
        auto base_pos = crab_table[i];
        for (int j = 0; j <= max_horizontal_dist; j++) {
            fuel_table[i][j] = calc_fuel(base_pos, j);
        }
    }

    int min_fuel_cost{INT_MAX};
    for (int i = 0; i <= max_horizontal_dist; i++) {
        auto fuel_cost{0};
        for (int j = 0; j < num_crabs; j++) {
            fuel_cost += fuel_table[j][i]; 
        }
        min_fuel_cost = min(fuel_cost, min_fuel_cost);
    }

    cout << "Ans = " << min_fuel_cost << endl;        
    return 0;
}