#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // 2 points are always a straight line
        if (coordinates.size() == 2) {
            return true;
        }
        int num_cord = coordinates.size();
        auto slope = [&](vector<int> c1, vector<int> c2) { return ((double)(c1[1] - c2[1]) / (double)(c1[0] - c2[0]));};
        const double s = slope(coordinates[1], coordinates[0]);
        for (int i = 2; i < num_cord; i++) {
            double this_slope = slope(coordinates[0], coordinates[i]);
            if (this_slope != s) {
                return false;
            }
        }        
        return true;
    }
};

int main() {
    vector<vector<int>> test{{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};

    Solution s;

    cout << s.checkStraightLine(test);
    return 0;
}