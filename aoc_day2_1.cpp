#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    string dir;
    int dist;
    pair<int, int> pos{0, 0}; // horz, vert

    while (cin >> dir >> dist) {
        cout << dir << " " << dist << endl;
        if (dir == "forward") {
            pos.first += dist;
        } else if (dir == "down") {
            pos.second += dist;
        } else if (dir == "up") {
            pos.second -= dist;
        } else {
            assert(0);
        }
    }

    cout << pos.first << " " << pos.second << endl;
    cout << "ans = " << (pos.first * pos.second) << endl; 
    return 0;
}