#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <map>
using namespace std;

// Class for operations on Line Segment
struct line {
    // Start and End of Segment
    pair<int, int> start;
    pair<int, int> end;
    line(int x1, int y1, int x2, int y2) : start{x1, y1}, end{x2, y2} {}
    
    // Vertical Line
    bool is_equal_x() {
        return (start.first == end.first);
    }

    // Horizontal Line
    bool is_equal_y() {
        return (start.second == end.second);
    }
    
    // Print co-ordinates of Line Segment
    void print() {
        cout << start.first << " : " << start.second << " | " << end.first << " : " << end.second << endl;
    }
    
    // Get all the co-ordinates making up the segment
    vector<pair<int, int>> points() {
        vector<pair<int, int>> ps;
        bool is_diag{false};

        // 45 degree diagonal line, slope should be 1 
        if (abs(start.first - end.first) == abs(start.second - end.second)) {
            is_diag = true;
        }

        // Only consider 45degree, vertical and horizontal segments
        if (is_diag or is_equal_x() or is_equal_y()) {
            // x1, y1 -> x2, y2
            // x1 < x2
            // x1 > x2
            // y1 < y2
            // y1 > y2
            auto x1 = start.first;
            auto y1 = start.second;
            auto x2 = end.first;
            auto y2 = end.second;
            // Just trace the line co-ordinate point wise from start to end points
            while (x1 != x2 or y1 != y2) {
                ps.push_back({x1, y1});
                if (x1 < x2) {
                    x1++;
                } else if (x1 > x2) {
                    x1--;
                }

                if (y1 < y2) {
                    y1++;
                } else if (y1 > y2) {
                    y1--;
                }
            }
            ps.push_back({x2, y2});
        }

        return ps;
    }
};

int main() {
    string lstr;
    vector<line> lines;
    
    // Parse input test case
    while (getline(cin, lstr)) {
        stringstream stream(lstr);
        int x1, y1, x2, y2;
        char comma, dash, brkt;
        stream >> x1 >> comma >> y1 >> dash >> brkt >> x2 >> comma >> y2;
        // Add this line segment to vector
        lines.push_back({x1, y1, x2, y2});
    }

    int ans{0};
    // store all co-ordinates in map
    // intesections will have 2 or more counts
    map<pair<int, int>, int> intersect;
    for (auto line : lines) {
        auto points = line.points();
        for (auto p : points) {
            intersect[p]++;
        }
    }

    for (auto kv : intersect) {
        if (kv.second >= 2) {
            ans++;
        }
    }

    cout << "Ans = " << ans << endl;
    return 0;
}