#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {
    struct line {
        pair<int, int> start;
        pair<int, int> end;
        line(int x1, int y1, int x2, int y2) : start{x1, y1}, end{x2, y2} {}
        bool is_equal_x() {
            return (start.first == end.first);
        }
        bool is_equal_y() {
            return (start.second == end.second);
        }        
        void print() {
            cout << start.first << " : " << start.second << " | " << end.first << " : " << end.second << endl;
        }

        vector<pair<int, int>> points() {
            vector<pair<int, int>> ps;
            bool is_diag{false};

            if (abs(start.first - end.first) == abs(start.second - end.second)) {
                is_diag = true;
            }
            if (is_diag) {
                // x1, y1 -> x2, y2
                // x1 < x2
                // x1 > x2
                // y1 < y2 
                // y1 > y2 
                auto x1 = start.first;
                auto y1 = start.second;
                auto x2 = end.first;
                auto y2 = end.second;
                while (x1 != x2 && y1 != y2) {
                    ps.push_back({x1, y1});
                    if (x1 < x2) {
                        x1++;
                    } else {
                        x1--;
                    }

                    if (y1 < y2) {
                        y1++;
                    } else {
                        y1--;
                    }

                }
                ps.push_back({x2, y2});
            } else if (is_equal_x()) {
                int i = start.first;
                int j = start.second;
                int k = end.second;
                if (j > k) {
                    swap(j, k);
                }

                for (int l = j; l <= k; l++) {
                // cout << i << " , " << l << endl;
                    ps.push_back({i, l});
                }
            } else if (is_equal_y()) {
                int i = start.second;
                int j = start.first;
                int k = end.first;
                if (j > k) {
                    swap(j, k);
                }

                for (int l = j; l <= k; l++) {
                    // cout << i << " , " << l << endl;
                    ps.push_back({l, i});
                }
            }
            return ps;
        } 
    };

    string lstr;
    vector<line> lines;
    while (getline(cin, lstr)) {
        stringstream stream(lstr);
        int x1, y1, x2, y2;
        char comma, dash, brkt;
        stream >> x1 >> comma >> y1 >> dash >> brkt >> x2 >> comma >> y2;
        lines.push_back({x1, y1, x2, y2});
    }

    int ans{0};
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