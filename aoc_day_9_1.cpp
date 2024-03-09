#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int find_risk_level(vector<vector<int>> &grid) {
    int r_level{0};
    auto is_valid = [&](int r, int c) {
        if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size()) {
            return false;
        }
        return true;
    };

    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[i].size(); j++) {
            int my_level = grid[i][j];

            bool is_low{true};
            for (auto p : dir) {
                if (is_valid(i + p.first, j + p.second)) {
                    if (grid[i + p.first][j + p.second] <= my_level) {
                        is_low = false;
                        break;
                    }
                }
            }
            if (is_low) {
                r_level += (my_level + 1);
            }
        }
    }

    return r_level;    
}

int main() {
    string line;
    vector<vector<int>> grid;
    int ans{0}; 
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> row;
        for (char digit; ss >> digit; ) {
            row.push_back(digit - '0');
        }
        grid.push_back(row);
    }
    ans = find_risk_level(grid);
    cout << "Ans: " << ans << endl;
    return 0;
}