#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    string dir;
    int dist;
    pair<int, int> pos{0, 0}; // horz, depth
    int aim{0};

    while (cin >> dir >> dist) {
        cout << dir << " " << dist << endl;
        if (dir == "forward") {
            pos.first += dist;
            pos.second += (aim * dist);
        } else if (dir == "down") {
            aim += dist;
        } else if (dir == "up") {
            aim -= dist;
        } else {
            assert(0);
        }
    }

    cout << pos.first << " " << pos.second << endl;
    cout << "ans = " << (pos.first * pos.second) << endl; 
    return 0;
}